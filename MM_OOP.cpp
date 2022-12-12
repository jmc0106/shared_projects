#include <iostream>
#include <cstdlib>
using namespace std;

class Team{
public:
    string TeamName;
    int Wins;
    int Loses;
    double Seed;
    string Division;
public:;
    Team(string team_name, int wins, int loses, double seed, string division){
        TeamName = team_name;
        Wins = wins;
        Loses = loses;
        Division = division;
        Seed = seed;
    }
};

class Team_West : public Team{
public:
    Team_West(string team_name, int wins, int loses, double seed, string division = "West"):Team(team_name, wins, loses, seed, division){}
};

class Team_East : public Team{
public:
    Team_East(string team_name, int wins, int loses, double seed, string division = "East"):Team(team_name, wins, loses, seed, division){}

};

class Team_South : public Team{
public:
    Team_South(string team_name, int wins, int loses, double seed, string division = "South"):Team(team_name, wins, loses, seed, division){}
};

class Team_MidW : public Team{
public:
    Team_MidW(string team_name, int wins, int loses, double seed, string division = "Midwest"):Team(team_name, wins, loses, seed, division){}
};

Team Game(Team team_a, Team team_b){
    double team_a_range = (team_a.Wins-team_a.Loses)*(1/team_a.Seed);
    double team_b_range = (team_b.Wins-team_b.Loses)*(1/team_b.Seed);
    srand(time(0));
    int rand_range = team_a_range + team_b_range;
    double randint = rand() % rand_range + 1;
    double randint_decimal = double(rand())/double(RAND_MAX);
    if(randint + randint_decimal <= team_a_range){
        cout << team_a.TeamName << " W | " <<  team_b.TeamName << " L" << endl;
        return team_a;
    }else{
        cout << team_b.TeamName << " W | " <<  team_a.TeamName << " L" << endl;
        return team_b;
    }
}

Team Conference_Bracket(Team t1, Team t2, Team t3, Team t4, Team t5, Team t6, Team t7, Team t8, Team t9, Team t10, Team t11, Team t12, Team t13, Team t14, Team t15, Team t16){
    
    cout << string(5, '*') << t1.Division << " conference bracket" << string(5,'*') << endl;
    cout << string(5, '*') << "Round 1" << string(5,'*') << endl;
    Team r1_g1 = Game(t1, t16);
    Team r1_g2 = Game(t8, t9);
    cout << string(25, '-') << endl;
    Team r1_g3 = Game(t5, t12);
    Team r1_g4 = Game(t4, t13);
    cout << string(25, '-') << endl;
    Team r1_g5 = Game(t6, t11);
    Team r1_g6 = Game(t3, t14);
    cout << string(25, '-') << endl;
    Team r1_g7 = Game(t7, t10);
    Team r1_g8 = Game(t2, t15);
    cout << string(25, '-') << endl << endl;

    cout << string(5, '*') << "Round 2" << string(5,'*') << endl;
    Team r2_g1 = Game(r1_g1, r1_g2);
    Team r2_g2 = Game(r1_g3, r1_g4);
    cout << string(25, '-') << endl;
    Team r2_g3 = Game(r1_g5, r1_g6);
    Team r2_g4 = Game(r1_g7, r1_g8);
    cout << string(25, '-') << endl << endl;

    cout << string(5, '*') << "Round 3" << string(5,'*') << endl;
    Team r3_g1 = Game(r2_g1, r2_g2);
    Team r3_g2 = Game(r2_g3, r2_g4);
    cout << string(25, '-') << endl << endl;

    cout << string(5, '*') << "Conference Finals" << string(5,'*') << endl;
    Team conference_winner = Game(r3_g1, r3_g2);
    cout << string(25, '*') << endl;
    cout << conference_winner.TeamName << " is moving on to the final four!!!" << endl;
    cout << endl << endl;
    
    return conference_winner;
}

void Final_Four(Team t1, Team t2, Team t3, Team t4){
    Team team_a = Game(t1, t2);
    cout << string(20,'*') << endl;
    cout << team_a.TeamName << " is moving onto the championship game!!!" << endl;
    cout << string(20,'*') << endl << endl;

    Team team_b = Game(t3, t4);
    cout << string(20,'*') << endl;
    cout << team_b.TeamName << " is moving onto the championship game!!!" << endl;
    cout << string(20,'*') << endl << endl;

    Team winner = Game(team_a, team_b);
    cout << string(20,'*') << endl;
    cout << string(20,'*') << endl;
    cout << winner.TeamName << " wins march madness!!!!!" << endl;
    cout << string(20,'*') << endl;
    cout << string(20,'*') << endl << endl;
}

int main(){

    Team_West T1w("Gonzaga", 26, 0, 1);
    Team_West T2w("Iowa", 21, 8, 2);
    Team_West T3w("Kansas", 20, 8, 3);
    Team_West T4w("Virginia", 18, 6, 4);
    Team_West T5w("Creighton", 20, 8, 5);
    Team_West T6w("USC", 22, 7, 6);
    Team_West T7w("Oregon", 20, 6, 7);
    Team_West T8w("Oklahoma", 15, 10, 8);
    Team_West T9w("Missouri", 16, 9, 9);
    Team_West T10w("VCU", 19, 7, 10);
    Team_West T11w("Drake", 25, 4, 11);
    Team_West T12w("UCSB", 22, 4, 12);
    Team_West T13w("Ohio", 16, 7, 13);
    Team_West T14w("Eastern Wash.", 16, 7, 14);
    Team_West T15w("Grand Canyon", 17, 6, 15);
    Team_West T16w("Norfolk St.", 16, 7, 16);

    Team_East T1e("Michigan", 20, 4, 1);
    Team_East T2e("Alabama", 24, 6, 2);
    Team_East T3e("Texas", 19, 7, 3);
    Team_East T4e("Florida St.", 16, 6, 4);
    Team_East T5e("Colorado", 22, 8, 5);
    Team_East T6e("BYU", 20, 6, 6);
    Team_East T7e("UConn", 15, 7, 7);
    Team_East T8e("LSU", 18, 9, 8);
    Team_East T9e("St. Bonaventure", 16, 4, 9);
    Team_East T10e("Maryland", 16, 13, 10);
    Team_East T11e("UCLA", 17, 9, 11);
    Team_East T12e("Georgetown", 13, 12, 12);
    Team_East T13e("UNC Greensboro", 21, 8, 13);
    Team_East T14e("Abil. Christian", 23, 4, 14);
    Team_East T15e("Iona", 12, 5, 15);
    Team_East T16e("Texas Southern", 16, 8, 16);

    Team_South T1s("Baylor", 22, 2, 1);
    Team_South T2s("Ohio St.", 21, 9, 2);
    Team_South T3s("Arkansas", 22, 6, 3);
    Team_South T4s("Purdue", 18, 9, 4);
    Team_South T5s("Villanova", 16, 6, 5);
    Team_South T6s("Texas Tech", 17, 10, 6);
    Team_South T7s("Florida", 14, 9, 7);
    Team_South T8s("North Carolina", 18, 10, 8);
    Team_South T9s("Wisconsin", 17, 12, 9);
    Team_South T10s("Virginia Tech", 15, 6, 10);
    Team_South T11s("Utah St.", 20, 8, 11);
    Team_South T12s("Winthrop", 23, 1, 12);
    Team_South T13s("North Texas", 17, 9, 13);
    Team_South T14s("Colgate", 14, 1, 14);
    Team_South T15s("Oral Roberts", 16, 10, 15);
    Team_South T16s("Hartford", 15, 8, 16);

    Team_MidW T1mw("Illinois", 23, 6, 1);
    Team_MidW T2mw("Houston", 24, 3, 2);
    Team_MidW T3mw("West Virginia", 18, 9, 3);
    Team_MidW T4mw("Oklahoma St.", 20, 8, 4);
    Team_MidW T5mw("Tennessee", 18, 8, 5);
    Team_MidW T6mw("San Diego St.", 23, 4, 6);
    Team_MidW T7mw("Clemson", 16, 7, 7);
    Team_MidW T8mw("Loyola Chicago", 24, 4, 8);
    Team_MidW T9mw("Georgia Tech", 17, 8, 9);
    Team_MidW T10mw("Rutgers", 15, 11, 10);
    Team_MidW T11mw("Syracuse", 16, 9, 11);
    Team_MidW T12mw("Oregon St.", 17, 12, 12);
    Team_MidW T13mw("Liberty", 23, 5, 13);
    Team_MidW T14mw("Morehead St.", 23, 7, 14);
    Team_MidW T15mw("Cleveland St.", 19, 7, 15);
    Team_MidW T16mw("Drexel", 12, 7, 16);

    Team midwest_conference_winner = Conference_Bracket(T1mw, T2mw, T3mw, T4mw, T5mw, T6mw, T7mw, T8mw, T9mw, T10mw, T11mw, T12mw, T13mw, T14mw, T15mw, T16mw);
    Team south_conference_winner = Conference_Bracket(T1s, T2s, T3s, T4s, T5s, T6s, T7s, T8s, T9s, T10s, T11s, T12s, T13s, T14s, T15s, T16s);
    Team east_conference_winner = Conference_Bracket(T1e, T2e, T3e, T4e, T5e, T6e, T7e, T8e, T9e, T10e, T11e, T12e, T13e, T14e, T15e, T16e);
    Team west_conference_winner = Conference_Bracket(T1w, T2w, T3w, T4w, T5w, T6w, T7w, T8w, T9w, T10w, T11w, T12w, T13w, T14w, T15w, T16w);

    Final_Four(west_conference_winner, east_conference_winner, south_conference_winner, midwest_conference_winner);

    return 0;
} 