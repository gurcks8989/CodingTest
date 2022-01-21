class Solution {
public:
    bool checkRecord(string s) {
        int cnt_A = 0, stack_L = 0 ;
        for(auto attendance : s){
            if(1 < cnt_A || 2 < stack_L)
                return false ;
            switch(attendance){
                case 'A':   cnt_A += 1 ;    stack_L = 0 ;   break ;
                case 'L':   stack_L += 1 ;                  break ;
                case 'P':   stack_L = 0 ;                   break ;
            }
        }
        if(1 < cnt_A || 2 < stack_L)
            return false ;
        return true ;
    }
};