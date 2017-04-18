#ifndef __INBRED_PATH_H
#define __INBRED_PATH_H

class path {

public:
    
    string type ;
    int start ;
    int stop ;
    
};

vector<path> read_path_file ( string input_file ) {

    vector<path> inbred_path ;
    
    ifstream PATH ( input_file.c_str() ) ;
    while ( !PATH.eof() ) {
        path new_path ;
        PATH >> new_path.type ;
        PATH >> new_path.start ;
        PATH >> new_path.stop ;
        inbred_path.push_back( new_path ) ;
    }
    inbred_path.pop_back() ;
    
    return inbred_path ;
}

#endif

