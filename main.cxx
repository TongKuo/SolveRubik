///:
/*****************************************************************************
 **                                                                         **
 **                               .======.                                  **
 **                               | INRI |                                  **
 **                               |      |                                  **
 **                               |      |                                  **
 **                      .========'      '========.                         **
 **                      |   _      xxxx      _   |                         **
 **                      |  /_;-.__ / _\  _.-;_\  |                         **
 **                      |     `-._`'`_/'`.-'     |                         **
 **                      '========.`\   /`========'                         **
 **                               | |  / |                                  **
 **                               |/-.(  |                                  **
 **                               |\_._\ |                                  **
 **                               | \ \`;|                                  **
 **                               |  > |/|                                  **
 **                               | / // |                                  **
 **                               | |//  |                                  **
 **                               | \(\  |                                  **
 **                               |  ``  |                                  **
 **                               |      |                                  **
 **                               |      |                                  **
 **                               |      |                                  **
 **                               |      |                                  **
 **                   \\    _  _\\| \//  |//_   _ \// _                     **
 **                  ^ `^`^ ^`` `^ ^` ``^^`  `^^` `^ `^                     **
 **                                                                         **
 **                    Copyright © 1997-2013 by Tong G.                     **
 **                          ALL RIGHTS RESERVED.                           **
 **                                                                         **
 ****************************************************************************/

#include "RubikCubeGlobal.hxx"

#include <iostream>
#include <string>

int main( int _Argc, char* *_Argv )
	{
	_Color _Red = _Color::_Red;
	_Color _Orange = _Color::_Orange;
	_Color _Blue = _Color::_Blue;
	_Color _Green = _Color::_Green;
	_Color _Yellow = _Color::_Yellow;
	_Color _White = _Color::_White;

	_3x3RubikCube _Cube
		{ { _Yellow, _Red, _Red, _Yellow, _Red, _Yellow, _Red, _Red, _Yellow }
		, { _White, _Orange, _Green, _Yellow, _Orange, _Blue, _Green, _Orange, _Orange }
		, { _Yellow, _Green, _Blue, _Yellow, _Blue, _Orange, _Blue, _Blue, _Blue }
		, { _Yellow, _Red, _Red, _Red, _Green, _Green, _Orange, _Green, _White }
		, { _Red, _Blue, _Green, _Orange, _Yellow, _Green, _Orange, _Blue, _Blue }
		, { _White, _White, _Green, _White, _White, _White, _White, _White, _Orange }
		};

	_Cube._Print();
	_Cube._SolveRubikCube();
	_Cube._Print();
#
	return 0;
	};

 ////////////////////////////////////////////////////////////////////////////

 /***************************************************************************
 **                                                                        **
 **      _________                                      _______            **
 **     |___   ___|                                   / ______ \           **
 **         | |     _______   _______   _______      | /      |_|          **
 **         | |    ||     || ||     || ||     ||     | |    _ __           **
 **         | |    ||     || ||     || ||     ||     | |   |__  \          **
 **         | |    ||     || ||     || ||     ||     | \_ _ __| |  _       **
 **         |_|    ||_____|| ||     || ||_____||      \________/  |_|      **
 **                                           ||                           **
 **                                    ||_____||                           **
 **                                                                        **
 ***************************************************************************/
///:~