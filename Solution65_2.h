#pragma once
#include<string>
#include<unordered_map>
class Solution
{
private:
	enum State
	{
		STATE_INITIAL,
		STATE_INT_SIGN,
		STATE_INTEGER,
		STATE_POINT,
		STATE_POINT_WITHOUT_INT,
		STATE_FRACTION,
		STATE_EXP,
		STATE_EXP_SIGN,
		STATE_EXP_NUMBER,
		STATE_END
	};
	enum CharType
	{
		CHAR_NUMBER,
		CHAR_EXP,
		CHAR_POINT,
		CHAR_SIGN,
		CHAR_ILLEGAL
	};
	CharType toCharType(char ch) {
		if ('0' <= ch && ch <= '9')
			return CHAR_NUMBER;
		else if (ch == 'e' || ch == 'E')
			return CHAR_EXP;
		else if (ch == '.')
			return CHAR_POINT;
		else if (ch == '-' || ch == '+')
			return CHAR_SIGN;
		else
			return CHAR_ILLEGAL;
	}

public:
	bool isNumber(std::string s) {
		using namespace std;
        unordered_map<State, unordered_map<CharType, State>> transfer = {
            {
                STATE_INITIAL, {
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_POINT, STATE_POINT_WITHOUT_INT},
                    {CHAR_SIGN, STATE_INT_SIGN}
                }
            }, {
                STATE_INT_SIGN, {
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_POINT, STATE_POINT_WITHOUT_INT}
                }
            }, {
                STATE_INTEGER, {
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_EXP, STATE_EXP},
                    {CHAR_POINT, STATE_POINT}
                }
            }, {
                STATE_POINT, {
                    {CHAR_NUMBER, STATE_FRACTION},
                    {CHAR_EXP, STATE_EXP}
                }
            }, {
                STATE_POINT_WITHOUT_INT, {
                    {CHAR_NUMBER, STATE_FRACTION}
                }
            }, {
                STATE_FRACTION,
                {
                    {CHAR_NUMBER, STATE_FRACTION},
                    {CHAR_EXP, STATE_EXP}
                }
            }, {
                STATE_EXP,
                {
                    {CHAR_NUMBER, STATE_EXP_NUMBER},
                    {CHAR_SIGN, STATE_EXP_SIGN}
                }
            }, {
                STATE_EXP_SIGN, {
                    {CHAR_NUMBER, STATE_EXP_NUMBER}
                }
            }, {
                STATE_EXP_NUMBER, {
                    {CHAR_NUMBER, STATE_EXP_NUMBER}
                }
            }
        };
        int sSize = s.size();
        State st = STATE_INITIAL;
        for (int i = 0; i < sSize; ++i) {
            CharType charType = toCharType(s[i]);
            if (transfer[st].find(charType) == transfer[st].end())
                return false;
            else
                st = transfer[st][charType];
        }
		return st==STATE_INTEGER|| st == STATE_POINT
            || st == STATE_FRACTION || st == STATE_EXP_NUMBER || st == STATE_END;
	}
};

