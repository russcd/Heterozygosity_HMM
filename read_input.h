#ifndef __READ_INPUT_H
#define __READ_INPUT_H

string read_input_file ( string input_file ) {
 
    string input ;
    ifstream FA ( input_file.c_str() ) ;
    getline( FA, input ) ;
    getline( FA, input ) ;
        
    return input ;
}

#endif

