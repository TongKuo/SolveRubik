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

#include "3x3RubikCube.h"
#include "RubikCubeGlobal.hxx"

#include <algorithm>
#include <iostream>
#include <stdexcept>

_AbstractRubikCube::_RevoleDegree
	operator "" _deg( unsigned long long _Val )
	{
	switch ( _Val )
		{
	case 90:  return _AbstractRubikCube::_RevoleDegree::_90Degree;
	case 180: return _AbstractRubikCube::_RevoleDegree::_180Degree;
	case 270: return _AbstractRubikCube::_RevoleDegree::_270Degree;

	default:  throw std::invalid_argument( "# Invalid degree #" );
		}
	}

 // _3x3RubikCube class implementation.

 	// ------------------- Public member functions ------------------- //

 	/* Constrcutor function */
 	_3x3RubikCube::_3x3RubikCube(
 		  std::initializer_list< _Color > const& _Front
		, std::initializer_list< _Color > const& _Rear
		, std::initializer_list< _Color > const& _Left
		, std::initializer_list< _Color > const& _Right
		, std::initializer_list< _Color > const& _Top
		, std::initializer_list< _Color > const& _Bottom )
 		{
	 	_InitializeSurface( _Front,  m_FrontSurface  );
	 	_InitializeSurface( _Rear,   m_RearSurface   );
	 	_InitializeSurface( _Left,   m_LeftSurface   );
	 	_InitializeSurface( _Right,  m_RightSurface  );
	 	_InitializeSurface( _Top,    m_TopSurface    );
	 	_InitializeSurface( _Bottom, m_BottomSurface );
 		}

 	/* _SolveRubikCube() function */
 	_AbstractRubikCube::_OperationMakers _3x3RubikCube
 		::_SolveRubikCube()
 		{
 		try {
 			// _FrontSurface_Left();
 			} catch ( std::invalid_argument const& _Ex )
 				{
 				std::cerr << _Ex.what()
 						  << " Please correct it"
 						  	 "( valid degree: 90_deg, 180_deg, 270_deg )."
 						  << std::endl;
 				}

 		return _AbstractRubikCube::_OperationMakers();
 		}

 	/* _Print() function */
 	void _3x3RubikCube::_Print() const
 		{
 		_PrintSpecifiedSurface( m_TopSurface, "  \t  " );

 		for ( int _Index = 0; _Index < _Oders; _Index++ )
 			{
 			_PrintSpecifiedLayer( m_LeftSurface, _Index, " " );

 			_PrintSpecifiedLayer( m_FrontSurface, _Index, " " );

 			_PrintSpecifiedLayer( m_RightSurface, _Index, " " );

			_PrintSpecifiedLayer( m_RearSurface, _Index, " " );

 			std::cout << std::endl;
 			}

 		_PrintSpecifiedSurface( m_BottomSurface, "  \t  " );
 		}

 	// ------------------ Private member functions ------------------- //

 	/* _PrintSpecifiedSurface() function */
 	void _3x3RubikCube
 		::_PrintSpecifiedSurface( _Surface const& __surface
 								, std::string const& _PlaceHolder ) const
 		{
 		for ( int _Row = 0; _Row < _Oders; _Row++ )
 			{
 			for ( int _Col = 0; _Col < _Oders; _Col++ )
 				if ( !( _Col % 3 ) )
 					std::cout << std::endl << _PlaceHolder;

 			_PrintLayer( __surface[ _Row ] );
 			}

 		std::cout << std::endl << std::endl;
 		}

 	/* _PrintSpecifiedSurface_Layer() function */
 	void _3x3RubikCube
 		::_PrintSpecifiedLayer( _Surface const& __surface
 							  , int _LayerNum
 							  , std::string const& _PlaceHolder ) const
 		{
 		_PrintLayer( *( __surface.begin() + _LayerNum ) );

 		std::cout << _PlaceHolder;
 		}

 	/* _PrintLayer() function */
 	void _3x3RubikCube
 		::_PrintLayer( std::array< _Color, _Oders > const& _Layer ) const
 		{
 		std::for_each( _Layer.begin(), _Layer.end()
 					 , []( _Color _Elem )
						{
						switch ( _Elem )
 							{
						case _Color::_Red:    std::cout << "R  "; break;
						case _Color::_Orange: std::cout << "O  "; break;
						case _Color::_Blue:   std::cout << "B  "; break;
						case _Color::_Green:  std::cout << "G  "; break;
						case _Color::_Yellow: std::cout << "Y  "; break;
						case _Color::_White:  std::cout << "W  "; break;
							}
						}
					 );
 		}

 	/* _InitializeSurface() function */
 	void _3x3RubikCube
 		::_InitializeSurface( std::initializer_list< _Color > const& _InitList
 							, _Surface& __surface )
 		{
 		std::initializer_list< _Color >::iterator 
 								_Iter = _InitList.begin();

 		for ( int _Row = 0; _Row < _Oders; _Row++ )
 			for ( int _Col = 0; _Col < _Oders; _Col++ )
				__surface[ _Row ][ _Col ] = *_Iter++;
 		}

 	// Rubik cubes' basic operational functions.

 	// _RevoleSpecifiedSurface() function */
 	void _3x3RubikCube
 		::_RevoleSpecifiedSurface( _Surface& __surface
 								 , _RevoleDirection _Direction
 								 , _RevoleDegree _Degree )
 		{
 		using _Layer = std::array< _Color, _Oders >;

 		_Layer _TempTopLayer;
 		for ( int _Index = 0; _Index < _Oders; _Index++ )
 			_TempTopLayer.at( _Index ) =
 				__surface[ 0 ].at( _Index );

 		_Layer _TempBottomLayer;
 		for ( int _Index = 0; _Index < _Oders; _Index++ )
 			_TempBottomLayer.at( _Index ) = 
 				__surface[ 2 ].at( _Index );

 		_Layer _TempLeftLayer;
 		for ( int _Index = 0; _Index < _Oders; _Index++ )
 			_TempLeftLayer.at( _Index ) = 
 				__surface[ _Index ].at( 0 );

 		_Layer _TempRightLayer;
 		for ( int _Index = 0; _Index < _Oders; _Index++ )
 			_TempRightLayer.at( _Index ) = 
 				__surface[ _Index ].at( 2 );

 		__surface.at( 0 ).swap( _TempRightLayer );
 		__surface.at( 2 ).swap( _TempLeftLayer );

 		// TODO


 	// 	switch ( _Direction )
 	// 		{
		// case _Degree::_90Degree:
		// 	if ( _Direction == 
 	// 		}
 		}

	/* Front surface */
	void _3x3RubikCube
		::_FrontSurface_Left( _RevoleDegree _Degree )
		{
		_RevoleSpecifiedSurface( m_FrontSurface
							   , _RevoleDirection::_Left );
		}

	void _3x3RubikCube
		::_FrontSurface_Right( _RevoleDegree _Degree )
		{
		// TODO
		}

	/* Rear surface */
	void _3x3RubikCube
		::_RearSurface_Left( _RevoleDegree _Degree )
		{
		// TODO
		}
		
	void _3x3RubikCube
		::_RearSurface_Right( _RevoleDegree _Degree )
		{
		// TODO
		}
		
	/* Left surface */
	void _3x3RubikCube
		::_LeftSurface_Forward( _RevoleDegree _Degree )
		{
		// TODO
		}

	void _3x3RubikCube
		::_LeftSurface_Backward( _RevoleDegree _Degree )
		{
		// TODO
		}
		
	/* Right surface */
	void _3x3RubikCube
		::_RightSurface_Forward( _RevoleDegree _Degree )
		{
		// TODO
		}
		
	void _3x3RubikCube
		::_RightSurface_Backward( _RevoleDegree _Degree )
		{
		// TODO
		}
		
	/* Top surface */
	void _3x3RubikCube
		::_TopSurface_Left( _RevoleDegree _Degree )
		{
		// TODO
		}

	void _3x3RubikCube
		::_TopSurface_Right( _RevoleDegree _Degree )
		{
		// TODO
		}

	/* Bottom surface */
	void _3x3RubikCube
		::_BottomSurface_Left( _RevoleDegree _Degree )
		{
		// TODO
		}

	void _3x3RubikCube
		::_BottomSurface_Right( _RevoleDegree _Degree )
		{
		// TODO
		}

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