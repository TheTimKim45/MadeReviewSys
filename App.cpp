//Our main App folder
#include <iostream>
#include "MadeScore.h"
#include "MadeList.h"

//Main() is our backend testing function
int main() 
{
	using namespace ML;
	using namespace MS;
	MadeList importedList;
	importedList.ImportList();
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

	testScore.Set_DIV_Grade(testScore.Get_M(), testScore.CalcDivCat(0));
	testScore.Set_DIV_Grade(testScore.Get_A(), testScore.CalcDivCat(1));
	testScore.Set_DIV_Grade(testScore.Get_D(), testScore.CalcDivCat(2));
	testScore.Set_DIV_Grade(testScore.Get_E(), testScore.CalcDivCat(3));

	testScore.CalculateFinalGrade();
	
	//Add testScore to ScoreList
	importedList.AddToList("TankHead", testScore);
	importedList.DisplayList();
	//testScore.Print_Menu();

	return 0;
}