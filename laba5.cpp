#include "laba5_head.h"

using namespace std;

int main()
{
    vector<Candidate> array_candidates;
    vector<string> array_name_candidates;
    vector<float> array_number_votes;
    float summary_votes;
    for (int k = 1, i = 0; i < 5; i++, ++k)
    {
        array_candidates.push_back(Candidate());
        cout << "Print data " << k << " Candidate. ( NAME, NUMBER_VOTES ) " << endl;
        cin >> array_candidates[i];
    }
    for (int i = 0; i < 5; i++)
    {
        array_name_candidates.push_back(array_candidates[i].name_candidate);
        array_number_votes.push_back(array_candidates[i].number_votes);
        summary_votes = summary_votes + array_candidates[i].number_votes;
    }
    // to change the data type from vector to string.
    string array_name_candidates_string[array_name_candidates.size()]; 
    // to change the data type from vector to float.
    float array_number_votes_float[array_number_votes.size()];
    for (int i = 0; i < 5; i++)
    {
        array_name_candidates_string[i] = array_name_candidates[i];
        array_number_votes_float[i] = array_number_votes[i];
        array_candidates[i].print_data();
        array_candidates[i].get_summary_votes(summary_votes);
        array_candidates[i].get_percent_votes();
    }
    Elections GetWinner;
    GetWinner.candidate_winner(array_name_candidates_string, array_number_votes_float);
}