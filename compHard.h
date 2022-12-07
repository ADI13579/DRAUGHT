//#ifndef computer
//#define computer


#pragma once
#include"Board.h"

class Pc_hard :virtual public initialBoard
{
public:
	void makeMoveC(sf::RenderWindow& window)
	{
		bool ok = false;
		//loop to make multistep move
		for (int i = 0; i < 8; i++)
		{
			if (ok)
				break;
			for (int j = 0; j < 8; j++)
			{
				if (ok)
					break;
				if (initPos[i][j] == 3)
				{
					if ((initPos[i - 1][j - 1] == 2 || initPos[i - 1][j - 1] == 4) && initPos[i - 2][j - 2] == 0 && (i - 2) >= 0 && (j - 2) >= 0)
					{
						if ((initPos[i - 3][j - 3] == 2 || initPos[i - 3][j - 3] == 4) && initPos[i - 4][j - 4] == 0 && (i - 4) >= 0 && (j - 4) >= 0)
						{
							initPos[i][j] = 0;
							initPos[i - 1][j - 1] = 0;
							initPos[i - 3][j - 3] = 0;
							initPos[i - 4][j - 4] = 3;
							ok = true;
						}
						else if ((initPos[i - 3][j - 1] == 2 || initPos[i - 3][j - 1] == 4) && initPos[i - 4][j] == 0 && (i - 4) >= 0)
						{
							initPos[i][j] = 0;
							initPos[i - 1][j - 1] = 0;
							initPos[i - 3][j - 1] = 0;
							initPos[i - 4][j] = 3;
							ok = true;
						}
						else if ((initPos[i - 1][j - 3] == 2 || initPos[i - 1][j - 3] == 4) && initPos[i][j - 4] == 0 && (j - 4) >= 0)
						{
							initPos[i][j] = 0;
							initPos[i - 1][j - 1] = 0;
							initPos[i - 1][j - 3] = 0;
							initPos[i][j - 4] = 3;
							ok = true;
						}
						else
						{
							//does nothing
						}
					}
					else if ((initPos[i - 1][j + 1] == 2 || initPos[i - 1][j + 1] == 4) && initPos[i - 2][j + 2] == 0 && (i - 2) >= 0 && (j + 2) <= 7)
					{
						if ((initPos[i - 3][j + 3] == 2 || initPos[i - 3][j + 3] == 4) && initPos[i - 4][j + 4] == 0 && (i - 4) >= 0 && (j + 4) <= 7)
						{
							initPos[i][j] = 0;
							initPos[i - 1][j + 1] = 0;
							initPos[i - 3][j + 3] = 0;
							initPos[i - 4][j + 4] = 3;
							ok = true;
						}
						else if ((initPos[i - 3][j + 1] == 2 || initPos[i - 3][j + 1] == 4) && initPos[i - 4][j] == 0 && (i - 4) >= 0)
						{
							initPos[i][j] = 0;
							initPos[i - 1][j + 1] = 0;
							initPos[i - 3][j + 1] = 0;
							initPos[i - 4][j] = 3;
							ok = true;
						}
						else if ((initPos[i - 1][j + 3] == 2 || initPos[i + 1][j + 3] == 4) && initPos[i][j + 4] == 0 && (j + 4) <= 7)
						{
							initPos[i][j] = 0;
							initPos[i - 1][j + 1] = 0;
							initPos[i - 1][j + 3] = 0;
							initPos[i][j + 4] = 3;
							ok = true;
						}
						else
						{
							//does nothing
						}
					}
					else if ((initPos[i + 1][j - 1] == 2 || initPos[i + 1][j - 1] == 4) && initPos[i + 2][j - 2] == 0 && (i + 2) <= 7 && (j - 2) >= 0)
					{
						if ((initPos[i + 3][j - 3] == 2 || initPos[i + 3][j - 3] == 4) && initPos[i + 4][j - 4] == 0 && (i + 4) <= 7 && (j - 4) >= 0)
						{
							initPos[i][j] = 0;
							initPos[i + 1][j - 1] = 0;
							initPos[i + 3][j - 3] = 0;
							initPos[i + 4][j - 4] = 3;
							ok = true;
						}
						else if ((initPos[i + 3][j - 1] == 2 || initPos[i + 3][j - 1] == 4) && initPos[i + 4][j] == 0 && (i + 4) <= 7)
						{
							initPos[i][j] = 0;
							initPos[i + 1][j - 1] = 0;
							initPos[i + 3][j - 1] = 0;
							initPos[i + 4][j] = 3;
							ok = true;
						}
						else if ((initPos[i + 1][j - 3] == 2 || initPos[i + 1][j - 3] == 4) && initPos[i][j - 4] == 0 && (j - 4) >= 0)
						{
							initPos[i][j] = 0;
							initPos[i + 1][j - 1] = 0;
							initPos[i + 1][j - 3] = 0;
							initPos[i][j - 4] = 3;
							ok = true;
						}
						else
						{
							//does nothing
						}
					}
					else if ((initPos[i + 1][j + 1] == 2 || initPos[i + 1][j + 1] == 4) && initPos[i + 2][j + 2] == 0 && (i + 2) <= 7 && (j + 2) <= 7)
					{
						if ((initPos[i + 3][j + 3] == 2 || initPos[i + 3][j + 3] == 4) && initPos[i + 4][j + 4] == 0 && (i + 4) <= 7 && (j + 4) <= 7)
						{
							initPos[i][j] = 0;
							initPos[i + 1][j + 1] = 0;
							initPos[i + 3][j + 3] = 0;
							initPos[i + 4][j + 4] = 3;
							ok = true;
						}
						else if ((initPos[i + 3][j + 1] == 2 || initPos[i + 3][j + 1] == 4) && initPos[i + 4][j] == 0 && (i + 4) <= 7)
						{
							initPos[i][j] = 0;
							initPos[i + 1][j + 1] = 0;
							initPos[i + 3][j + 1] = 0;
							initPos[i + 4][j] = 3;
							ok = true;
						}
						else if ((initPos[i + 1][j + 3] == 2 || initPos[i + 1][j + 3] == 4) && initPos[i][j + 4] == 0 && (j + 4) <= 7)
						{
							initPos[i][j] = 0;
							initPos[i + 1][j + 1] = 0;
							initPos[i + 1][j + 3] = 0;
							initPos[i][j + 4] = 3;
							ok = true;
						}
						else
						{
							//does nothing
						}
					}
					else
					{
						//does nothing
					}
				}
				else if (initPos[i][j] == 1 && (initPos[i + 1][j + 1] == 2 || initPos[i + 1][j + 1] == 4) && initPos[i + 2][j + 2] == 0 && (j + 2) <= 7 && (i+2)<=7)
				{
					if ((initPos[i + 3][j + 3] == 2 || initPos[i + 3][j + 3] == 4) && initPos[i + 4][j + 4] == 0 && (j + 4) <= 7 && (i+4)<=7)
					{
						initPos[i][j] = 0;
						initPos[i + 1][j + 1] = 0;
						initPos[i + 3][j + 3] = 0;
						initPos[i + 4][j + 4] = 1;
						makeKing();
						ok = true;
					}
					else if ((initPos[i + 3][j + 1] == 2 || initPos[i + 3][j + 1] == 4) && initPos[i + 4][j] == 0 && (i+4)<=7)
					{
						initPos[i][j] = 0;
						initPos[i + 1][j + 1] = 0;
						initPos[i + 3][j + 1] = 0;
						initPos[i + 4][j] = 1;
						makeKing();
						ok = true;
					}
					else
					{
						//nothing
					}
				}
				else if (initPos[i][j] == 1 && (initPos[i + 1][j - 1] == 2 || initPos[i + 1][j - 1] == 4) && initPos[i + 2][j - 2] == 0 && (i+2)<=7 && (j - 2) >= 0)
				{
					if ((initPos[i + 3][j - 3] == 2 || initPos[i + 3][j - 3] == 4) && initPos[i + 4][j - 4] == 0 && (j - 4) >= 0 && (i+4)<=7)
					{
						initPos[i][j] = 0;
						initPos[i + 1][j - 1] = 0;
						initPos[i + 3][j - 3] = 0;
						initPos[i + 4][j - 4] = 1;
						makeKing();
						ok = true;
					}
					else if ((initPos[i + 3][j - 1] == 2 || initPos[i + 3][j - 1] == 4) && initPos[i + 4][j] == 0 && (i+4)<=7)
					{
						initPos[i][j] = 0;
						initPos[i + 1][j - 1] = 0;
						initPos[i + 3][j - 1] = 0;
						initPos[i + 4][j] = 1;
						makeKing();
						ok = true;
					}
					else
					{
						//nothing
					}
				}
			}
		}
		//loop to mave single step move
		for (int i = 0; i < 8; i++)
		{
			if (ok)
				break;
			for (int j = 0; j < 8; j++)
			{
				if (ok)
					break;
				if (initPos[i][j] == 3) //single scoring move for king
				{
					if ((initPos[i - 1][j - 1] == 2 || initPos[i - 1][j - 1] == 4) && initPos[i - 2][j - 2] == 0 && (i - 2) >= 0 && (j - 2) >= 0)
					{
						initPos[i][j] = 0;
						initPos[i - 1][j - 1] = 0;
						initPos[i - 2][j - 2] = 3;
						ok = true;
					}
					else if ((initPos[i - 1][j + 1] == 2 || initPos[i - 1][j + 1] == 4) && initPos[i - 2][j + 2] == 0 && (i - 2) >= 0 && (j + 2) <= 7)
					{
						initPos[i][j] = 0;
						initPos[i - 1][j + 1] = 0;
						initPos[i - 2][j + 2] = 3;
						ok = true;
					}
					else if ((initPos[i + 1][j - 1] == 2 || initPos[i + 1][j - 1] == 4) && initPos[i + 2][j - 2] == 0 && (i + 2) <= 7 && (j - 2) >= 0)
					{
						initPos[i][j] = 0;
						initPos[i + 1][j - 1] = 0;
						initPos[i + 2][j - 2] = 3;
						ok = true;
					}
					else if ((initPos[i + 1][j + 1] == 2 || initPos[i + 1][j + 1] == 4) && initPos[i + 2][j + 2] == 0 && (i + 2) <= 7 && (j + 2) <= 7)
					{
						initPos[i][j] = 0;
						initPos[i + 1][j + 1] = 0;
						initPos[i + 2][j + 2] = 3;
						ok = true;
					}
					else
					{
						//does nothing
					}
				}
				else if (initPos[i][j] == 1 && (initPos[i + 1][j + 1] == 2 || initPos[i + 1][j + 1] == 4) && initPos[i + 2][j + 2] == 0 && (j + 2) <= 7 && (i+2)<=7)
				{
					initPos[i][j] = 0;
					initPos[i + 1][j + 1] = 0;
					initPos[i + 2][j + 2] = 1;
					makeKing();
					ok = true;
				}
				else if (initPos[i][j] == 1 && (initPos[i + 1][j - 1] == 2 || initPos[i + 1][j - 1] == 4) && initPos[i + 2][j - 2] == 0 && (j - 2) >= 0 && (i+2)<=7 )
				{
					initPos[i][j] = 0;
					initPos[i + 1][j - 1] = 0;
					initPos[i + 2][j - 2] = 1;
					makeKing();
					ok = true;
				}
				else
				{
					//nothing
				}
			}
		}
		//loop to give chance for begineer
		for (int i = 0; i < 8; i++)
		{
			if (ok)
				break;
			for (int j = 0; j < 8; j++)
			{
				if (ok)
					break;
				if (initPos[i][j] == 1 && initPos[i + 1][j + 1] == 0 && (j + 2) <= 7 && (i + 2) <= 7 && ((initPos[i + 2][j + 2] == 2 || initPos[i + 2][j + 2] == 4) || (((initPos[i + 2][j] == 2) || (initPos[i + 2][j] == 4)) && initPos[i][j + 2] == 0) || (initPos[i][j + 2] == 4 && initPos[i + 2][j] == 0)))
				{
					initPos[i][j] = 0;
					initPos[i + 1][j + 1] = 1;
					makeKing();
					ok = true;
				}
				else if (initPos[i][j] == 1 && initPos[i + 1][j - 1] == 0 && (j - 2) >= 0 && (i + 2) <= 7 && ((initPos[i + 2][j - 2] == 2 || initPos[i + 2][j - 2] == 4) || (((initPos[i + 2][j] == 2) || (initPos[i + 2][j] == 4)) && initPos[i - 2][j] == 0) || (initPos[i - 2][j] == 4 && initPos[i + 2][j] == 0)))
				{
					initPos[i][j] = 0;
					initPos[i + 1][j - 1] = 1;
					makeKing();
					ok = true;
				}
				else if (initPos[i][j] == 3)
				{
					if (initPos[i - 1][j - 1] == 0 && (i - 2) >= 0 && (j - 2) >= 0 && (((initPos[i][j - 2] == 2 || initPos[i][j - 2] == 4) && (initPos[i - 2][j] == 0)) || (initPos[i - 2][j] == 4 && initPos[i][j - 2] == 0) || (initPos[i - 2][j - 2] == 4)))
					{
						initPos[i][j] = 0;
						initPos[i - 1][j - 1] = 3;
						ok = true;
					}
					else if (initPos[i - 1][j + 1] == 0 && (i - 2) >= 0 && (j + 2) <= 7 && (((initPos[i][j + 2] == 2 || initPos[i][j + 2] == 4) && (initPos[i - 2][j] == 0)) || (initPos[i - 2][j] == 4 && initPos[i][j + 2] == 0) || (initPos[i - 2][j + 2] == 4)))
					{
						initPos[i][j] = 0;
						initPos[i - 1][j + 1] = 3;
						ok = true;
					}
					else if (initPos[i + 1][j - 1] == 0 && (i + 2) <= 7 && (j - 2) >= 0 && (((initPos[i + 2][j] == 2 || initPos[i + 2][j] == 4) && (initPos[i][j + 2] == 0)) || (initPos[i][j - 2] == 4 && initPos[i + 2][j] == 0) || (initPos[i + 2][j - 2] == 2 || initPos[i + 2][j - 2] == 4)))
					{
						initPos[i][j] = 0;
						initPos[i + 1][j - 1] = 3;
						ok = true;
					}
					else if (initPos[i + 1][j + 1] == 0 && (i + 2) <= 7 && (j + 2) <= 7 && (((initPos[i + 2][j] == 2 || initPos[i + 2][j] == 4) && (initPos[i][j + 2] == 0)) || (initPos[i][j + 2] == 4 && initPos[i + 2][j] == 0) || (initPos[i - 2][j - 2] == 2 || initPos[i + 2][j + 2] == 4)))
					{
						initPos[i][j] = 0;
						initPos[i + 1][j + 1] = 3;
						ok = true;
					}
					else
					{
						//does nothing
					}
				}
				else
				{
					//does nothing
				}
			}
		}
		//loop just to make move
		for (int i = 0; i < 8; i++)
		{
			if (ok)
				break;
			for (int j = 0; j < 8; j++)
			{
				if (ok)
					break;
				if (initPos[i][j] == 1 && initPos[i + 1][j + 1] == 0 && (j + 1) <= 7 && (i+1)<=7)
				{
					initPos[i][j] = 0;
					initPos[i + 1][j + 1] = 1;
					makeKing();
					ok = true;
				}
				else if (initPos[i][j] == 1 && initPos[i + 1][j - 1] == 0 && (j - 1) >= 0 && (i+1)<=7)
				{
					initPos[i][j] = 0;
					initPos[i + 1][j - 1] = 1;
					makeKing();
					ok = true;
				}
				else if (initPos[i][j] == 3)
				{
					if (initPos[i - 1][j - 1] == 0 && (i - 1) >= 0 && (j - 1) >= 0)
					{
						initPos[i][j] = 0;
						initPos[i - 1][j - 1] = 3;
						ok = true;
					}
					else if (initPos[i - 1][j + 1] == 0 && (i - 1) >= 0 && (j + 1) <= 7)
					{
						initPos[i][j] = 0;
						initPos[i - 1][j + 1] = 3;
						ok = true;
					}
					else if (initPos[i + 1][j - 1] == 0 && (i + 1) <= 7 && (j - 1) >= 0)
					{
						initPos[i][j] = 0;
						initPos[i + 1][j - 1] = 3;
						ok = true;
					}
					else if (initPos[i + 1][j + 1] == 0 && (i + 1) <= 7 && (j + 1) <= 7)
					{
						initPos[i][j] = 0;
						initPos[i + 1][j + 1] = 3;
						ok = true;
					}
					else
					{
						//does nothing
					}
				}
				else
				{
					//does nothing
				}
			}

		}
		
		for (int i = 0; i < 8; i++)
		{
			std::cout << std::endl;
			for (int j = 0; j < 8; j++)
			{
				std::cout << initPos[i][j];
			}
		}
		// usleep(2000);
		setBoard(window);
		if (setBoard(window) == 1)
		{
			msg.setString("White wins");
			window.draw(msg);
			window.display();
			system("Pause");
		}
		else if (setBoard(window) == 2)
		{
			msg.setString("Black wins");
			window.draw(msg);
			window.display();
			system("Pause");
		}
	}
	void makeKing()
	{
		for (int k = 0; k < 8; k++)
		{
			if (initPos[7][k] == 1)
			{
				initPos[7][k] = 3;
			}
		}
	}
};

