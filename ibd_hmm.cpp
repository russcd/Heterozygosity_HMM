/// headers
#include <iostream>
#include <vector>
#include <map>
#include <time.h>
#include <string>
#include <fstream>
#include <algorithm>
#include <math.h>
using namespace std ;

/// our header files in /src
#include "cmd_line.h"
#include "read_cmd_line.h"
#include "read_input.h" 
#include "parameters.h" 
#include "viterbi.h" 

int main ( int argc, char *argv[] ) {
    
    /// precision
    
    
   	// read cmd line
	cmd_line options ;
    cerr << "reading command line" << endl ;
	options.read_cmd_line( argc, argv ) ;
    
    cerr << "reading input file" << endl ;
    string chrom = read_input_file( options.input_file ) ;
    cerr << "chromosome length " << chrom.size() << endl ; 
    
    /// read in file that has the transition rate per bp ( in windows is okay), or for every bp, also the approximate rate of differences  for outbred individuals and the rate for inbred individuals
    cerr << "reading parameter file" << endl ;
    vector<parameters> params = read_parameter_file( options.parameter_file, options.inbreeding_transition_rate ) ;
    cerr << "read " << params.size() << " windows" << endl ;

    /// do viterbi
    cerr << "computing viterbi inbred/outbred path " << endl ;
    viterbi( params, chrom ) ; 
    
    return 0 ;
}
	

