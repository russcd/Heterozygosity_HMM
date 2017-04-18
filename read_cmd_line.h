#ifndef __READ_CMD_LINE_H
#define __READ_CMD_LINE_H

void cmd_line::read_cmd_line ( int argc, char *argv[] ) {
    
    /// INBRED default is 3 transitions into per 1.5 morgans on average
    inbreeding_transition_rate = 0.5 ;
    
	/// accept command line parameters
	for (int i=1; i<argc; i++) {
        
        /// INBRED
        if ( strcmp(argv[i],"--inbred") == 0 ) {
            inbreeding_transition_rate = atof(argv[++i]) ;
        }
        
        // parameter file 
        if ( strcmp(argv[i],"-p") == 0 ) {
            parameter_file = string(argv[++i]) ;
        }
        
        /// input sample
        if ( strcmp(argv[i],"-i") == 0 ) {
            input_file = string(argv[++i]) ;
        }
    }
}

#endif

