#include <iostream>
#include <vector>
#include<curses.h>
#include<math.h>
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
#include <chrono>
using namespace std;
void euclidean_distance_adapted(vector<double> a_point,vector<double> b_point){
    double result=0;
    for(int i=0;i<a_point.size();i++){
        result+=pow(a_point[i]-b_point[i],2);
    }
    double sqrt(result);
    //does not return anything as it is not required
}
void test_()
{
    vector<int> elem_={5,10,15,20};
    vector<int> dim_={10000,15000,25000};
    for(int i=0;i<dim_.size();i++){
        for(int j=0;j<elem_.size();j++){
            cout<<"For "<<dim_[i]<<"dimensions with "<<elem_[j]<< "elements"<<endl;
            vector<vector<double>> this_vec;
            srand(time(NULL));
            for(int l=0;l<elem_[i];l++){
                vector<double> temp;
                for(int k=0;k<dim_[j];k++){
                    temp.push_back(rand()%elem_[i]+1);
                }
                this_vec.push_back(temp);
            }
            chrono::time_point<std::chrono::high_resolution_clock> start, end;
            start = std::chrono::high_resolution_clock::now();
            //Performing calculations
            for(int l=0;l<elem_[i];l++){
                for(int k=0;k<elem_[i];k++){
                    euclidean_distance_adapted(this_vec[l],this_vec[k]);
                }
            }
            end = std::chrono::high_resolution_clock::now();
            int64_t duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            cout<<"It would take: "<<duration<<" microseconds."<<endl;
        }
    }
}
int main()
{

    cout<<"Multidimensional curse test using vectors"<<endl<<endl;
    test_();
    return 0;
}

