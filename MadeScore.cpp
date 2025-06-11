#include "MadeScore.h"

namespace MS
{
	MadeScore::ScoreUnit::ScoreUnit()
	{
		s_grade = 0;
		s_weight = 3;
	}

	MadeScore::MadeScore()
	{
		//Initial Game Score
		GameGrade = 0;
	}

	void MadeScore::CalculateFinalGrade()
	{
		float calcGrade = ((GradeM.s_grade * GradeM.s_weight) +
			(GradeA.s_grade * GradeA.s_weight) +
			(GradeD.s_grade * GradeD.s_weight)) /
			(GradeM.s_weight + GradeA.s_weight + GradeD.s_weight);
		GameGrade = static_cast<int>(calcGrade + 0.5f);
	}

	void MadeScore::Set_Division_Grade(ScoreUnit& c1, ScoreUnit& c2, ScoreUnit& c3, ScoreUnit& divisionUnit)
	{
		float calcGrade = static_cast<float>(c1.s_weight * (c1.s_grade + 5));
		calcGrade += static_cast<float>(c2.s_weight * (c2.s_grade + 5));
		calcGrade += static_cast<float>(c3.s_weight * (c3.s_grade + 5));
		calcGrade /= static_cast<float>(c1.s_weight + c2.s_weight + c3.s_weight);
		calcGrade *= 10.f;
		divisionUnit.s_grade = static_cast<int>(calcGrade + 0.5f);
	}

	MadeScore::ResCode MadeScore::Set_SU_Grade(const int newGrade, ScoreUnit& scoreUnit)
	{
		if (newGrade >= -5 && newGrade <= 5)
		{
			scoreUnit.s_grade = newGrade;
			return SUCCESS;
		}
		else
			return ERROR;
	}

	MadeScore::ResCode MadeScore::Set_SU_Weight(const int newWeight, ScoreUnit& scoreUnit)
	{
		if (newWeight >= 0 && newWeight <= 5)
		{
			scoreUnit.s_weight = newWeight;
			return SUCCESS;
		}
		else
			return ERROR;
	}

	MadeScore::ResCode MadeScore::Set_Division_Weight(const int newWeight, ScoreUnit& divisionUnit)
	{
		if (newWeight >= 0 && newWeight <= 5)
		{
			divisionUnit.s_weight = newWeight;
			return SUCCESS;
		}
		else
			return ERROR;
	}
}
