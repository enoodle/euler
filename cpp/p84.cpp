#include <string>
//#include <sstream>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

#include <unordered_map>


#define EIGEN_STACK_ALLOCATION_LIMIT 536870912
#include "math/Eigen/Eigenvalues"
#include "math/Eigen/Dense"


using namespace std;

typedef Eigen::Matrix<double, 120, 120> TransferMatrix;

class cube_res{
    public:
        int v;
        double p;
        bool dd;
        cube_res(int val, double _p, bool d) : 
            v(val), p(_p), dd(d) {}
} ;

vector<cube_res> two_cubes_probs(int cube_size){
    vector<cube_res> p_vec;
    for (int i = 1; i <= cube_size; ++i){
        for (int j = 1; j <= cube_size; ++j){
            p_vec.push_back( cube_res ( i+j, 
                        1/double(cube_size*cube_size),
                        (i == j)));
        }
    }

    return p_vec;
}


string loc_type_name[] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "R", "U", 
    "CC", "CH", "JAIL", "FP", "G2J", "GO", "T"
};

typedef enum {
    A,B,C,D,E,F,G,H,R,U,CC,CH,JAIL,FP,G2J,GO,T
} LocationType;

class MonopolyLocation {
    public:
        typedef pair<double, int > transfer_option;
        typedef vector<transfer_option> transfer_list;

        MonopolyLocation(int ind, LocationType ltype, int bn, transfer_list trl) : 
            board_index(ind), ltype(ltype), block_number(bn), tr_list(trl) {}
        MonopolyLocation(int ind, LocationType ltype, int bn) : 
            board_index(ind), ltype(ltype), block_number(bn) {
            tr_list = transfer_list(1, transfer_option(1.0, ind));
        }

        virtual transfer_list get_transfers(){ return tr_list;}
        virtual transfer_list get_transfers(double p){
            transfer_list ntr_list;
            for (transfer_option& to: tr_list){
                ntr_list.push_back(
                        transfer_option(to.first*p, to.second));
            }
            return ntr_list;
        }

        virtual void set_transfer_list(transfer_list trl){
            tr_list = trl;
        }

        LocationType get_loc_type() { return ltype;}

        int get_index() { return board_index; }
        int get_block() { return block_number; }

        string get_full_name(){
            return loc_type_name[ltype] + std::to_string(block_number);
        }

    private:
        int board_index;
        LocationType ltype;
        int block_number;
        transfer_list tr_list;
};

void push_trl_ch(MonopolyLocation::transfer_list& trl,
        MonopolyLocation loc){
    trl.push_back(MonopolyLocation::transfer_option(1.0/16.0, 0));
    trl.push_back(MonopolyLocation::transfer_option(1.0/16.0, 10));
    trl.push_back(MonopolyLocation::transfer_option(1.0/16.0, 11));
    trl.push_back(MonopolyLocation::transfer_option(1.0/16.0, 24));
    trl.push_back(MonopolyLocation::transfer_option(1.0/16.0, 39));
    trl.push_back(MonopolyLocation::transfer_option(1.0/16.0, 5));
    trl.push_back(MonopolyLocation::transfer_option(1.0/16.0, loc.get_index()-3));
    switch (loc.get_block()){
        case 1:
            trl.push_back(MonopolyLocation::transfer_option(1.0/16.0, 15));
            trl.push_back(MonopolyLocation::transfer_option(1.0/16.0, 15));
            trl.push_back(MonopolyLocation::transfer_option(1.0/16.0, 12));
            break;
        case 2:
            trl.push_back(MonopolyLocation::transfer_option(1.0/16.0, 25));
            trl.push_back(MonopolyLocation::transfer_option(1.0/16.0, 25));
            trl.push_back(MonopolyLocation::transfer_option(1.0/16.0, 28));
            break;
        default:
            trl.push_back(MonopolyLocation::transfer_option(1.0/16.0, 5));
            trl.push_back(MonopolyLocation::transfer_option(1.0/16.0, 5));
            trl.push_back(MonopolyLocation::transfer_option(1.0/16.0, 12));
            break;
    }
    trl.push_back(MonopolyLocation::transfer_option(6.0/16.0, loc.get_index()));
}


void add_transfer_list(vector<MonopolyLocation>& board){
    // so static and ugly...
    for (MonopolyLocation& loc : board){
        MonopolyLocation::transfer_list trl;
        switch (loc.get_loc_type()){
            case CC:
                trl.push_back(MonopolyLocation::transfer_option(1.0/16.0, 0));
                trl.push_back(MonopolyLocation::transfer_option(1.0/16.0, 10));
                trl.push_back(MonopolyLocation::transfer_option(14.0/16.0, loc.get_index()));
                break;
            case G2J:
                trl.push_back(MonopolyLocation::transfer_option(1.0, 10));
                break;
            case CH:
                push_trl_ch(trl, loc);
                break;
            default:
                trl.push_back(MonopolyLocation::transfer_option(1.0, loc.get_index()));
                break;
        }
        loc.set_transfer_list(trl);
    }
}

vector<MonopolyLocation> create_board(LocationType loc_names[], int len){
    vector<MonopolyLocation> board;
    unordered_map<int, int> blocks;
    for (int ind = 0; ind < len; ++ind){
        int block_ind = 1;
        LocationType loc_name = loc_names[ind];
        auto it = blocks.find(loc_name);
        if (it == blocks.end()){
            blocks.insert(pair<int,int>(loc_name, 1));
        } else {
            it->second += 1;
            block_ind = it->second;
        }
        board.push_back(MonopolyLocation(ind, loc_name, block_ind));
    }
    add_transfer_list(board);
    return board;
}

TransferMatrix triple_layer_transfer_mat(vector<MonopolyLocation> board,
        int cube_size){
    TransferMatrix trm;
    for (MonopolyLocation& origin: board){
        for (cube_res& roll: two_cubes_probs(cube_size)){
            MonopolyLocation dest = board[
                (origin.get_index() + roll.v) % board.size()];
            for (MonopolyLocation::transfer_option& tro : 
                    dest.get_transfers(roll.p)){
                if (false == roll.dd){
                    trm(origin.get_index(), tro.second) += tro.first;
                    trm(origin.get_index() + 40, tro.second) += tro.first;
                    trm(origin.get_index() + 80, tro.second) += tro.first;
                } else {
                    trm(origin.get_index(), tro.second + 40) += tro.first;
                    trm(origin.get_index() + 40, tro.second + 80) += tro.first;
                    trm(origin.get_index() + 80, 10) += tro.first;
                }
            }
        }
    }
    return trm;
}

TransferMatrix generate_trans_matrix(int cube_size){

    LocationType loc_names[] = {
        GO,A,CC,A, T,R,B,CH, B, B, 
        JAIL, C, U, C, C, R, D, CC, D, D, 
        FP,E, CH, E, E, R, F, F, U, F,
        G2J, G, G, CC, G, R, CH, H, T, H
    };

    vector<MonopolyLocation> board = create_board(loc_names, 40);

    return triple_layer_transfer_mat(board, cube_size);
}

vector<pair<int, double> >top_3_probs(Eigen::VectorXcd v){
    vector<double> vec(40,0);
    double total = 0;
    for (unsigned int i = 0 ; i < v.size() ; ++i){
        vec[i % 40 ] += v[i].real();
        total += v[i].real();
    }
    for (unsigned int i = 0; i < vec.size(); ++i){
        vec[i] = vec[i]/total;
    }
    vector<double> sorted = vec;
    sort(sorted.begin(), sorted.end());

    vector<pair<int, double> > ret;
    for (double p : sorted){
        pair<int,double> loc;
        loc.second = p;
        loc.first = find(vec.begin(), vec.end(), p) - vec.begin();
        ret.push_back(loc);
    }

    return ret;
}

double row_sum(Eigen::VectorXcd r){
    double sum = 0;
    for (int i = 0 ; i < r.size(); ++i){
        sum+= r[i].real();
    }
    return sum;
}


int p84(int cube_size){

    // create matrix
    TransferMatrix trm = generate_trans_matrix(cube_size);

    cout << trm.col(10) << endl;
    cout << trm.row(10) << endl;
    cout << "trm.row(0)" << endl;
    cout << trm.row(0) << endl;

    for (int i = 0; i < trm.rows(); ++i){
        if (row_sum(trm.row(i)) != 1.0 ){
            cout << "problem with row " << i << endl;
            cout << "sum is " << row_sum(trm.row(i)) << endl;
        }
    }

    // find eigenvectors for eigenvalue 1
    Eigen::EigenSolver<TransferMatrix> eigen_solver(trm.transpose(), true);
    cout << eigen_solver.eigenvalues() << endl;
    cout << "for the first eigen value:" << endl;
    Eigen::MatrixXcd V = eigen_solver.eigenvectors();
    cout << V.col(0) << endl;
    Eigen::VectorXcd all_probs = V.col(0);

    //cout << eigen_solver.eigenvectors().col(0)[10] << endl;
    
    vector<pair<int, double> > probs = top_3_probs(all_probs);
    for (int i = 0; i < 3; ++i ){
        cout << probs[probs.size() - i-1].first << " , ";
        cout << probs[probs.size() - i-1].second << endl;
    }

    
    // check with initial probability?

    return 0;
}


int main(int argc, char** argv){
    if (argc == 2){
        string s(argv[1]);
        cout << p84(stoi(s)) << endl;
    }
    else{
        std::cout << p84(4) << std::endl;
    }
    return 0;
}


