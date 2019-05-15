#ifndef _CLIENT_
#define _CLINET_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
using namespace std;

struct Location
{
    string name;
    string has_back_location;
    string description;
    vector<string> near_locations;
    Location()
    {
        name = "";
        description = "";
        has_back_location = "";
    }
    string to_str()
    {
        string display_text = "";

        display_text.append("\n### " + name + " ###\n");
        display_text.append("\n" + description);

        for (unsigned int i = 1; i < near_locations.size(); i++)
        {
            if (i == near_locations.size() - 1 && has_back_location != "None")
            {
                display_text.append("\n[" + to_string(i) + "] Back\n");
            }
            else
            {
                if(near_locations[i][0] == '@')
                    near_locations[i] = near_locations[i].substr(1);
                
                display_text.append("\n[" + to_string(i) + "] " + near_locations[i]);
            }
        }

        display_text.append("\n");

        return display_text;
    }
};

class Client
{
    string world_map_file;
    string game_file;
    string locations_file;
    string items_file;
    string player_file;
    string monster_file;

public:
    Client()
    {
        world_map_file = "World.txt";
        game_file = "Game.txt";
        locations_file = "Locations.txt";
    }

    // Executing the Game
    void combat(map<string,string> event_data);
    void navigation(map<string,string> event_data);
    void fight(string _monster);
    string RNG_calculator(string object, string chance);

    // String Sparcers
    void cut_spaces_off_ends(string &str);
    void cut_spaces_off_ends(vector<string> &v);
    int count_and_cut_tabs(string str);
    vector<string>split(string str, char c);

    // Interacts with Txt files
    void set_value(string filename, string key, string value);
    string get_value(string filename, string key);
    vector<string> get_near_locations(string current_location);
    vector<pair<string, int>> get_All_locations_and_their_num_of_tabs();
    map<string, string> get_data(string current_event);

    // Interacts with Yaml
    void run();
    int get_user_input(int max, int min, string display_text);
};

#endif