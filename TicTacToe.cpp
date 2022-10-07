#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

bool valid(int x){
    if(x == 11){
        return true;
    }else if(x == 12){
        return true;
    }else if(x == 13){
        return true;
    }else if(x == 21){
        return true;
    }else if(x == 22){
        return true;
    }else if(x == 23){
        return true;
    }else if(x == 31){
        return true;
    }else if(x == 32){
        return true;
    }else if(x == 33){
        return true;
    }else{
        return false;
    }
}

string gameover(vector< vector<string> > v){
    for(int i = 0; i < 3; i++){
        if((v[i][0] == v[i][1] && v[i][1] == v[i][2] )&& v[i][0] != "---"){
            if(v[i][0] == "-X-"){
                return "X";
            }else if(v[i][0] == "-0-"){
                return "0";
            }
        }
    }
    for(int i = 0; i < 3; i++){
        if((v[0][i] == v[1][i] && v[1][i] == v[2][i] )&& v[0][i] != "---"){
            if(v[0][i] == "-X-"){
                return "X";
            }else if(v[0][i] == "-0-"){
                return "0";
            }
        }
    }
    if(v[0][0] == v[1][1] && v[1][1] == v[2][2]){
        if(v[0][0] == "-X-"){
            return "X";
        }else if(v[0][0] == "-0-"){
            return "0";
        }
    }
    if(v[2][0] == v[1][1] && v[1][1] == v[0][2]){
        if(v[1][1] == "-X-"){
            return "X";
        }else if(v[1][1] == "-0-"){
            return "0";
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(v[i][j] == "---"){
                return "LO";
            }
        }
    }
    return "L";

}

void printboard(vector< vector<string> > v){
    cout << "   1   2  3" << endl;
    for(int i = 0; i < 3; i++){
        cout << i+1 << " " << v[i][0] << " " << v[i][1] << " " << v[i][2] << endl;
    }
}

vector< vector<string> > changeboard(vector< vector<string> > v, int s, int t){
    int row = s/10;
    int col = s%10;
    if(t % 2 == 0){
        v[row - 1][col-1] = "-0-";
    }else{
        v[row - 1][col-1] = "-X-";
    }
    return v;
}

bool unfilled(int s, vector< vector<string> > board){
    int row = s/10;
    int col = s%10;
    string place = board[row-1][col-1];
    if(place == "---"){
        return true;
    }else{
        return false;
    }
}

int main(){
    string YES("yes");
    pa:
        bool playon = true;
        vector< vector<string> > board;
        for(int i = 0; i < 3; i++){
            vector<string> v;
            for(int i = 0; i < 3; i++){
                v.push_back("---");
            }
            board.push_back(v);
        }
    
        int t = 1;
        while(playon){
            system("clear");
            printboard(board);
            int s;
            cin >> s;

            if((valid(s) && unfilled(s, board) )&& !cin.fail()){
                board = changeboard(board, s,  t);
                t++;
            }else{

                validinput:
                    if(cin.fail()){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n' );
                    }
                    
                    cout << "Please Enter Valid Input" << endl;
                    int lol;
                    cin >> lol;
            
                if((!valid(lol) || !unfilled(lol, board)) || cin.fail())
                    goto validinput;
                else
                    board = changeboard(board, lol, t);
                    t++;
            
            //New Learning : goto keyword
            }
        
        
            if(gameover(board) == "X"){
                playon = false;
                system("clear");
                printboard(board);
                cout << "Player 1 Wins" << endl;
                cout << "Wanna Play Again?" << endl;
                string s; 
                cin >> s;
                if(s == YES){
                    goto pa;
                }
                
                

            }else if(gameover(board) == "0"){
                system("clear");
                printboard(board);
                cout << "Player 2 Wins" << endl;
                cout << "Wanna Play Again?" << endl;
                string s; 
                cin >> s;
                if(s == YES){
                    goto pa;
                }
                
            
            }else if(gameover(board) == "L"){
                playon = false;
                system("clear");
                printboard(board);
                cout << "Stalemate" << endl;
                cout << "Wanna Play Again?" << endl;
                string s; 
                cin >> s;
                if(s == YES){
                    goto pa;
                }
                
                
            }
        }
}
