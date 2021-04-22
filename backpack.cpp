#include<iostream>
#include<vector>
#include<cmath>


using std::vector;
using std::cout;
using std::cin;
using std::string;



class Item {

    int weight;
    int value;

public:

    Item(int w, int v) {
        weight = w;
        value = v;
    }

    int get_weight() {
        return weigth;
    }

    int get_value() {
        return value;
    }
  
};





class ItemArray() {
    vector<Item> contain;

public:

    ItemArray(vector<Items> arr) {
        contain = arr;
    }
};





class BackPack {

    int bp_weight;
    vector<Item> filling;

public:

    BackPack(int w) {
        bp_weight = w;   
    }



    int get_max_value(ItemArray arr) {
    
        vector<int> v_contain;
        v_contain.push_back(0);

        for (int i = 1; i <= bp_weight; ++i)
        {
            int b = -1;
            int t_b;
            for (int j = 0; j < arr.contain.size(); ++j)
            {
                if (arr.contain[j].weight <= i)
                {
                    t_b = v_contain[i - arr.contain[j].weight] + arr.contain[j].value;
                    b = (b > t_b) ? b : t_b;
                }
            }
            v_contain.push_back(b);
        }
        return v_contain[bp_weight];
    }
    
};



int main() {
    Item it1(4, 20);
    Item it2(3, 18);
    Item it3(2, 14);

    vector<Item> item_vec;

    item_vec.push_back(it1);
    item_vec.push_back(it2);
    item_vec.push_back(it3);


    ItemArray arr(item_vec);
    BackPack bp1(7);
    cout << bp1.get_max_value(arr) << std::endl;
}
