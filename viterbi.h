#ifndef __VITERBI_H
#define __VITERBI_H

void viterbi( const vector<parameters> &params, const string &chrom ) {
    
    int index = 0 ;
    string in_path = "I" ;
    string out_path = "O" ;
    vector<int> in_lengths (1,0) ;
    vector<int> out_lengths (1,0) ;
    double prob_in_path = 0 ;
    double prob_out_path = 0 ;
    
    for ( int i = 0 ; i < chrom.size() ; i ++ ) {
        
        /// iterate up to keep params relevant
        while ( i >= params[index+1].position ) {
            index ++ ;
        }
        
        /// emissions definitions for missing, homozygous, heterozygous
        double emissions_in = 0 ;
        double emissions_out = 0 ;
        if ( chrom[i] == 'A' || chrom[i] == 'T' || chrom[i] == 'C' || chrom[i] == 'G' ) {
            emissions_in = params[index].hom_prob_in ;
            emissions_out = params[index].hom_prob_out ;
        }
        else if ( chrom[i] != 'N' ) {
            emissions_in = params[index].het_prob_in ;
            emissions_out = params[index].het_prob_out ;
        }
        
        /// inbred paths
        double in2in = prob_in_path + params[index].no_rec + emissions_in ;
        double out2in = prob_out_path + params[index].rec + emissions_in ;
        
        /// outbred paths
        double in2out = prob_in_path + params[index].rec + emissions_out ;
        double out2out = prob_out_path + params[index].no_rec + emissions_out ;
        
        /// new paths
        string new_in_path ;
        string new_out_path ;
        vector<int> new_in_lengths ;
        vector<int> new_out_lengths ;
        
        /// update in path
        if ( in2in > out2in ) {
            prob_in_path = in2in ;
            new_in_path = in_path ;
            new_in_lengths = in_lengths ;
            new_in_lengths.back() ++ ;
        }
        else {
            prob_in_path = out2in ;
            new_in_path = out_path + "I" ;
            new_in_lengths = out_lengths ;
            new_in_lengths.push_back(1) ;
        }
                
        /// update out path
        if ( in2out > out2out ) {
            prob_out_path = in2out ;
            new_out_path = in_path + "O" ;
            new_out_lengths = in_lengths ;
            new_out_lengths.push_back(1) ;
        }
        else {
            prob_out_path = out2out ;
            new_out_path = out_path ;
            new_out_lengths = out_lengths ;
            new_out_lengths.back() ++ ;
        }
        
        cerr << i << "\t" << prob_in_path << "\t" << prob_out_path ;
        cerr << "\t" << params[index].no_rec << "\t" << params[index].rec ;
        cerr << "\t" << emissions_in << "\t" << emissions_out << endl ;
        
        /// swap paths
        swap( new_out_path, out_path ) ;
        swap( new_in_path, in_path ) ;
        swap( new_out_lengths, out_lengths ) ;
        swap( new_in_lengths, in_lengths ) ;
    }
    
    string path = in_path ;
    vector<int> lengths = in_lengths ;
    if ( prob_out_path > prob_in_path ) {
        path = out_path ;
        lengths = out_lengths ;
    }
    
    int distance_travelled = 0 ;
    for ( int i = 0 ; i < path.size() ; i ++ ) {
        cout << path[i] << "\t" << distance_travelled << "\t" << distance_travelled + lengths[i] << endl ;
        distance_travelled += lengths[i] ;
    }
}

#endif

