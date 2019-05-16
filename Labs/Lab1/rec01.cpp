//Alex Mosseri
//Rec01
//Conways game of life

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream game_life("life.txt");
    if (!game_life) {
        cerr << "Could not open the file.\n";
        exit(1);
    }

}
    vector <string> lines;
    while (!game_life.eof()) {
        string line;
        getline(game_life, line);
        lines.push_back(line);
        cout << line << endl;
    }
    game_life.close();

    vector <string> new_board;
    for (int x =0; x < 8; ++x){
        string foo;
        for (int y = 0; y < 20; ++y){
            foo.push_back('-');
        }
        new_board.push_back(foo);
        cout << foo << endl;
    }
    for (size_t done = 0; done < 10; ++done){
        cout<< endl;
        for (size_t i = 0; i < lines.size() ; ++i){
            string board_line = lines[i];
            for (size_t j = 0; j < board_line.size() ; ++j){
                //cout << lines[i][j];
                //cout << endl;
                int temp_count = 0;
                if (i > 0 && i < lines.size()){
                    if (lines[i-1][j] == '*'){
                        ++temp_count;
                    }
                    if (lines[i+1][j] == '*'){
                        ++temp_count;
                    }
                    if (j > 0){
                        if (lines[i-1][j-1] == '*'){
                            ++temp_count;
                        }
                        if (lines[i][j-1] == '*'){
                            ++temp_count;
                        }
                        if (lines[i+1][j-1] == '*'){
                            ++temp_count;
                        }
                    }
                    
                    if (j < lines[i].size()){
                        if (lines[i+1][j+1] == '*'){
                            ++temp_count;
                        }
                        
                        if (lines[i-1][j+1] == '*'){
                            ++temp_count;
                        }
                        if (lines[i][j+1] == '*'){
                            ++temp_count;
                        }
                    }
                    
                }
                
                
                else{
                    if (i > 0){
                        if (lines[i-1][j] == '*'){
                            ++temp_count;
                        }
                        if (j > 0){
                            if (lines[i-1][j-1] == '*'){
                                ++temp_count;
                            }
                            if (lines[i][j-1] == '*'){
                                ++temp_count;
                            }
                        }
                        if (j < lines[i].size()){
                        
                            if (lines[i-1][j+1] == '*'){
                                ++temp_count;
                            }
                            if (lines[i][j+1] == '*'){
                                ++temp_count;
                            }
                        }
                    }
                    if (i < lines.size()){
                        if (lines[i+1][j] == '*'){
                            ++temp_count;
                        }
                        if (j > 0){
                            if (lines[i+1][j-1] == '*'){
                                ++temp_count;
                            }
                            if (lines[i][j-1] == '*'){
                                ++temp_count;
                            }
                        }
                        if (j < lines[i].size()){
                        
                            if (lines[i+1][j+1] == '*'){
                                ++temp_count;
                            }
                            if (lines[i][j+1] == '*'){
                                ++temp_count;
                            }
                        }
                    }
                }
                if (lines[i][j] == '*'){
                    if (temp_count == 3 || temp_count == 2){
                        new_board[i][j] = '*';
                    }
                    else{
                        new_board[i][j] = '-';
                    }
                }
                else{
                    if (temp_count == 3){
                        new_board[i][j] = '*';
                    }
                    else{
                        new_board[i][j] = '-';
                        
                    }
                }
                
                    
            }
                
        } 
        for ( size_t i = 0; i < new_board.size(); ++i){
            cout << new_board[i] << endl; 
            
        }
        lines = new_board;  
    }
}  



    
    
   


    









   // for (string line: lines ){
    //    for (char b: line){
    //        cout << b ;
    //    }
   
