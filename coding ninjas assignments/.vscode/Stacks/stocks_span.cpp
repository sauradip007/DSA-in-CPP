#include<iostream>
using namespace std;
#include<stack>
int stockspan(int a[] , int n)
{
    // //output returned in array
    // stack<int>s;
    // int i = 1;
    // int span[n];
    // int t;
    // s.push(a[0]);
    // span[0] = 1;
    // //on first day stock will be at its best price
    // while(i < n )
    // {
    //     int count = 0;
    //     t = s.top();
    //     s.push(a[i]);
    //     if(s.top() < t )
    //     {
    //         span[i] = 1;
    //         //if next days price less than that of current day then 1 will be the span
    //     }
    //    else if(s.top() > t)
    //    {
          
    //         // stack<int>p;//making a temporary stack to store elements of all elements entered till THAT specific point
    //         // while(!s.empty())
    //         // {
    //         //     p.push(s.top());
    //         //     s.pop();
    //         // }
    //         // int r = p.top();

    //         // p.pop(); // for same day
    //         // count++;
    //         // if (r > p.top() && !p.empty())
    //         // {
    //         //     p.pop();
    //         //     count++;
    //         //    }
            

               
           
           
    //        span[i] = count;
           
    //    }
    //    else if(s.top() == t)
    //    {
    //        span[i] = 1;
    //        //equal prices dont count for span
    //    }

     
    //     i++;
    // }
    // int l = 0;
    // while(l < n)
    // {
    //     return span[i];
    // }
    stack<int>s;
    
    int span[n];
    
    for(int i = 0; i < n ; i++)
    {
      if(i == 0)
      {
          s.push(0);
          span[0] = 1;
      }
        
        
        if(a[i] < a[i-1])

        {
            
            span[i] = i - (i-1);
            s.push(i);
        }
        else{
            if(a[i] > a[s.top()] && !s.empty())
            {
                s.pop();
                
            }
            span[i] = i+1;
            s.push(i);
        }
       
        
        
    }
}