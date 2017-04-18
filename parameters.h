#ifndef __PARAMETERS_H
#define __PARAMETERS_H

class parameters {
    
public:
    
    int position ;
    double rec ;
    double no_rec ;
    double het_prob_out ;
    double hom_prob_out ;
    double het_prob_in ;
    double hom_prob_in ;
    
} ;

vector<parameters> read_parameter_file ( string param_file, double inbreeding_transition_rate ) {
    
    vector<parameters> param_set ;
    
    ifstream p ( param_file.c_str() ) ;
    while ( !p.eof() ) {
        parameters new_parameters ;
        p >> new_parameters.position ;
        p >> new_parameters.rec ;
        p >> new_parameters.het_prob_in ;
        p >> new_parameters.hom_prob_in ;
        p >> new_parameters.het_prob_out ;
        p >> new_parameters.hom_prob_out ;
        
        /// get prob hom from - 1 het
        new_parameters.hom_prob_in = log( 1 - new_parameters.het_prob_in ) ;
        new_parameters.hom_prob_out = log( 1 - new_parameters.het_prob_out ) ;
        
        /// take log so we can just sum them
        new_parameters.het_prob_in = log( new_parameters.het_prob_in ) ;
        new_parameters.het_prob_out = log( new_parameters.het_prob_out ) ;
        
        // rec too
        new_parameters.rec *= inbreeding_transition_rate ;
        new_parameters.no_rec = log( 1 - new_parameters.rec ) ;
        new_parameters.rec = log( new_parameters.rec ) ;
        
        param_set.push_back( new_parameters ) ;
    }
    
    param_set.pop_back() ; 
    
    parameters new_parameters ;
    new_parameters.position = 2147483647 ;
    param_set.push_back( new_parameters ) ;
    
    return param_set ;
}

#endif

