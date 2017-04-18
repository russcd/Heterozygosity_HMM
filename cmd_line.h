#ifndef __CMD_LINE_H
#define __CMD_LINE_H

/// command line information and global parameters
class cmd_line {
public:
    
    /// input file name
    string input_file ;
    
    /// parameter file name
    string parameter_file ; 
    
    /// INBREEDING TRANSITION RATE
    double inbreeding_transition_rate ; 
    
    /// read relevant information
    void read_cmd_line ( int argc, char *argv[] ) ;

} ;

#endif

