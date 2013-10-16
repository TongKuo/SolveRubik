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
		( { _Blue, _Blue, _Yellow, _Blue, _Red, _Yellow, _Green, _Red, _Orange }
		, { _Green, _Yellow, _White, _Blue, _Orange, _Orange, _Orange, _Orange, _Green }
		, { _Red, _Green, _White, _White, _Blue, _Red, _Red, _White, _White }
		, { _Blue, _Green, _White, _Blue, _Green, _White, _Yellow, _Green, _Yellow }
		, { _Blue, _Red, _Red, _Yellow, _Yellow, _Orange, _Orange, _Orange, _Red }
		, { _Orange, _Green, _Blue, _Red, _White, _White, _Yellow, _Yellow, _Green }
		);

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