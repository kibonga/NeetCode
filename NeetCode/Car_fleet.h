#pragma once
#include <utility>
#include <vector>
#include <stack>
#include <map>
using namespace std;

struct Car {
    int start_position;
    int velocity;
    int time_to_finish;
};

int car_fleet(int target, vector<int>& positions, vector<int>& speeds) {
    stack<Car> stack;
    vector<Car> elems;
    map<int, int> map;
    int i, V, t, S;
    Car car{}, next_car{};
    bool is_fleet;

    if (positions.empty()) {
        cout << "There are no cars" << endl;
        return -1;
    }

    for (i = 0; i < positions.size(); i++) {
        S = positions[i];
        V = speeds[i];
        map[S] = V;
    }

    for (auto& m : map) {
        car.start_position = m.first;
        car.velocity = m.second;
        car.time_to_finish = (target - car.start_position) / car.velocity;
        elems.push_back(car);
    }

    stack.push(elems[0]);

    for (i = 1; i < elems.size(); i++) {
        car = stack.top();
        next_car = elems[i];

        is_fleet = (car.start_position + (next_car.time_to_finish * car.velocity)) >= target;
        if (is_fleet) {
            stack.pop();
        }
        stack.push(next_car);
    }

    return stack.size();
}
