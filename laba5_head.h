#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Candidate
{ 
public:
    string name_candidate;
    float number_votes, summary_votes;
    Candidate()
    {
    }
    Candidate(string name_candidate, float number_votes)
    {
        this->name_candidate = name_candidate;
        this->number_votes = number_votes;
    }
    void print_data()
    {
        cout << endl
             << "Name candidate - " << name_candidate << " || ";
        cout << "Number votes - " << number_votes << " || ";
    }
    void get_summary_votes(float summary_votes)
    {
        this->summary_votes = summary_votes;
    }
    void get_percent_votes()
    {
        float percent_votes;
        percent_votes = 0;
        percent_votes = (number_votes / summary_votes) * 100;
        cout << "Percent votes " << percent_votes << " %" << endl;
    }
};
ostream &operator<<(ostream &os, const Candidate &other)
{
    os << other.name_candidate << other.number_votes << endl;
    return os;
}
istream &operator>>(istream &is, Candidate &other)
{
    is >> other.name_candidate >> other.number_votes;
    return is;
}
class Elections : public Candidate
{ 
private:
    string name_winner;
    float number_votes_winner;

public:
    void candidate_winner(string names_candidates[4], float number_votes[4])
    {
        number_votes_winner = 0;
        for (int i = 0; i < 5; i++)
        {
            if (number_votes[i] > number_votes_winner)
            {
                number_votes_winner = number_votes[i];
                name_winner = names_candidates[i];
            }
        }
        cout << "\n\n\n"
             << name_winner << " won by scoring - " << number_votes_winner << " votes!!!\n\n\n";
    }
};