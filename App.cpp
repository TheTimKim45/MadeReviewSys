//Our main App folder
#include <iostream>
#include "MadeScore.h"

//Main() is our backend testing function
int main() 
{
	//App Processes

	//Gathers FROM Local Database:
	//PART ONE:
	// STATIC FUNC - Read JSON file of DATABASE data into std::vector then CLOSE fstream
	//-Search Criteria Variables
	//-Distinguish Static vs Dynamic
	//-Present Options
	//-Wait and gather input from user (usually the 'SEARCH' Button)
	//PART TWO:
	//-Gathers inputs from user and runs CALC functions
	//-Calculate NEW RESULT SCORES from CALC Functions
	//-Use NEW SCORES to filter & retrieve list from internal std::vector ds
	//-Sort list (descending/ascending - user choice) according to USER SET PARAMETERS
	//ENCAPSULATE ABOVE in while loop WHILE StateMachine != STATE_EXIT
	//else if StateMachine == STATE_EXIT
	//Commence app termination process and cleanup

	//NOTE - Internal DS
	//Class madeScore:
	//M - Mechanics
	//A - Art
	//D - Development
	//E - Extra
	//Static = int grade <-- imported and populated from JSON values
	//Dynamic = float weight <-- Set by User During App Use
	// ImportList()
	// ExportList() <-- Phase 2 (Reviewer End)
	//Class lists
	//std::vector<madScore> initialImport <-- from JSON
	//std::vector<madScore> displayList <-- calculated, sorted, then displayed
	using namespace MS;
	MadeScore testScore;

	//TankHead Score Emulation Test
	//M_DIVISION_CAT
	testScore.Set_CAT_Grade(4, testScore.Get_M_C1());
	testScore.Set_CAT_Weight(4, testScore.Get_M_C1());
	
	testScore.Set_CAT_Grade(3, testScore.Get_M_C2());
	testScore.Set_CAT_Weight(2, testScore.Get_M_C2());

	testScore.Set_CAT_Grade(4, testScore.Get_M_C3());
	testScore.Set_CAT_Weight(4, testScore.Get_M_C3());

	testScore.Set_DIV_Weight(4, testScore.Get_M());

	//A_DIVISION_CAT
	testScore.Set_CAT_Grade(-1, testScore.Get_A_C1());
	testScore.Set_CAT_Weight(3, testScore.Get_A_C1());

	testScore.Set_CAT_Grade(5, testScore.Get_A_C2());
	testScore.Set_CAT_Weight(4, testScore.Get_A_C2());

	testScore.Set_CAT_Grade(5, testScore.Get_A_C3());
	testScore.Set_CAT_Weight(5, testScore.Get_A_C3());

	testScore.Set_DIV_Weight(4, testScore.Get_A());

	//D_DIVISION_CAT
	testScore.Set_CAT_Grade(4, testScore.Get_D_C1());
	testScore.Set_CAT_Weight(3, testScore.Get_D_C1());

	testScore.Set_CAT_Grade(5, testScore.Get_D_C2());
	testScore.Set_CAT_Weight(3, testScore.Get_D_C2());

	testScore.Set_CAT_Grade(4, testScore.Get_D_C3());
	testScore.Set_CAT_Weight(3, testScore.Get_D_C3());

	testScore.Set_DIV_Weight(3, testScore.Get_D());

	//E_DIVISION_CAT
	testScore.Set_CAT_Grade(0, testScore.Get_E_C1());
	testScore.Set_CAT_Weight(3, testScore.Get_E_C1());

	testScore.Set_CAT_Grade(0, testScore.Get_E_C2());
	testScore.Set_CAT_Weight(0, testScore.Get_E_C2());

	testScore.Set_CAT_Grade(1, testScore.Get_E_C3());
	testScore.Set_CAT_Weight(1, testScore.Get_E_C3());

	testScore.Set_DIV_Weight(3, testScore.Get_E());

	testScore.Set_DIV_Grade(testScore.Get_M_C1(), testScore.Get_M_C2(), testScore.Get_M_C3(), testScore.Get_M());
	testScore.Set_DIV_Grade(testScore.Get_A_C1(), testScore.Get_A_C2(), testScore.Get_A_C3(), testScore.Get_A());
	testScore.Set_DIV_Grade(testScore.Get_D_C1(), testScore.Get_D_C2(), testScore.Get_D_C3(), testScore.Get_D());
	testScore.Set_DIV_Grade(testScore.Get_E_C1(), testScore.Get_E_C2(), testScore.Get_E_C3(), testScore.Get_E());
	testScore.CalculateFinalGrade();
	
	testScore.Print_Menu();

	return 0;
}