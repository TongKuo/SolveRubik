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
 			_FrontSurface_Left();
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
 		_PrintSpecifiedSurface( m_TopSurface, "       " );

 		for ( int _Index = 0; _Index < _Oders; _Index++ )
 			{
 			_PrintSpecifiedLayer( m_LeftSurface, _Index, " " );

 			_PrintSpecifiedLayer( m_FrontSurface, _Index, " " );

 			_PrintSpecifiedLayer( m_RightSurface, _Index, " " );

			_PrintSpecifiedLayer( m_RearSurface, _Index, " " );

 			std::cout << std::endl;
 			}

 		_PrintSpecifiedSurface( m_BottomSurface, "       " );
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
						case _Color::_Red:    std::printf("\033[41;37m\033[4m \033[5m|"); break;
						case _Color::_Orange: std::printf("\033[43;37m\033[4m \033[5m|"); break;
						case _Color::_Blue:   std::printf("\033[44;37m\033[4m \033[5m|"); break;
						case _Color::_Green:  std::printf("\033[42;33m\033[4m \033[5m|"); break;
						case _Color::_Yellow: std::printf("\033[45;37m\033[4m \033[5m|"); break;
						case _Color::_White:  std::printf("\033[47;30m\033[4m \033[5m|"); break;
							}
						}
					 );

 		std::printf("\033[0m");
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
 		// TODO
 		_RotateLeft90Degree( __surface );

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

	// _Rotate 90 degree
	/* _RotateLeft90Degree() function */
	void _3x3RubikCube
		::_RotateLeft90Degree( _Surface& __surface )
		{
 		_Layer _LeftLayer = _GetSurfaceLeftLayer( __surface );

 		_Layer _RightLayer = _GetSurfaceRightLayer( __surface );

 		__surface.at( 0 ).swap( _RightLayer );
 		__surface.at( 2 ).swap( _LeftLayer );

 		for ( int _Index = 0; _Index < _Oders; _Index++ )
 			__surface[ _Index ][ 2 ] =
 				_RightLayer[ _Index ];

  		for ( int _Index = 0; _Index < _Oders; _Index++ )
 			__surface[ _Index ][ 0 ] =
 				_LeftLayer[ _Index ];


		}

	/* _RotateRight90Degree() function */
	void _3x3RubikCube
		::_RotateRight90Degree( _Surface& __surface )
		{

		}

	/* _RotateLeft180Degree() function */
	void _3x3RubikCube
		::_RotateLeft180Degree( _Surface& __surface )
		{

		}

	/* _RotateRight180Degree() function */
	void _3x3RubikCube
		::_RotateRight180Degree( _Surface& __surface )
		{

		}

	/* _RotateLeft270Degree() function */
	void _3x3RubikCube
		::_RotateLeft270Degree( _Surface& __surface )
		{

		}

	/* _RotateRight270Degree() function */
	void _3x3RubikCube
		::_RotateRight270Degree( _Surface& __surface )
		{

		}

	/* _GetSurfaceTopLayer() function */
	_3x3RubikCube::_Layer _3x3RubikCube
		::_GetSurfaceTopLayer( _Surface const& __surface ) const
		{
 		_Layer _TempTopLayer;
 		for ( int _Index = 0; _Index < _Oders; _Index++ )
 			_TempTopLayer[ _Index ] =
 				__surface[ 0 ][ _Index ];

 		return _TempTopLayer;		
		}

	/* _GetSurfaceBottomLayer() function */
	_3x3RubikCube::_Layer _3x3RubikCube
		::_GetSurfaceBottomLayer( _Surface const& __surface ) const
		{
 		_Layer _TempBottomLayer;
 		for ( int _Index = 0; _Index < _Oders; _Index++ )
 			_TempBottomLayer[ _Index ] = 
 				__surface[ 2 ][ _Index ];

 		return _TempBottomLayer;
		}

	/* _GetSurfaceLeftLayer() function */
	_3x3RubikCube::_Layer _3x3RubikCube
		::_GetSurfaceLeftLayer( _Surface const& __surface ) const
		{
 		_Layer _TempLeftLayer;
 		for ( int _Index = 0; _Index < _Oders; _Index++ )
 			_TempLeftLayer[ _Index ] = 
 				__surface[ _Index ][ 0 ];

 		return _TempLeftLayer;
		}

	/* _GetSurfaceRightLayer() function */
	_3x3RubikCube::_Layer _3x3RubikCube
		::_GetSurfaceRightLayer( _Surface const& __surface ) const
		{
 		_Layer _TempRightLayer;
 		for ( int _Index = 0; _Index < _Oders; _Index++ )
 			_TempRightLayer[ _Index ] = 
 				__surface[ _Index ][ 2 ];

 		return _TempRightLayer;
		}

	/* _GetBroadSideTopLayer() function */
	_3x3RubikCube::_Layer _3x3RubikCube
		::_GetBroadSideTopLayer( _Surface const& __surface ) const
		{
		_SurfaceType _CurrentSurfaceType = _GetSurfaceType( __surface );

		switch ( _CurrentSurfaceType )
			{
		case _SurfaceType::_Front:  return m_TopSurface[ 2 ];
		case _SurfaceType::_Rear:   return _GetInvertLayer( m_TopSurface[ 0 ] );
		case _SurfaceType::_Left:   return _GetSurfaceLeftLayer( m_TopSurface );
		case _SurfaceType::_Right:  return _GetInvertLayer( _GetSurfaceRightLayer( m_TopSurface ) );
		case _SurfaceType::_Top:    return _GetInvertLayer( m_RearSurface[ 0 ] );
		case _SurfaceType::_Bottom: return _GetInvertLayer( m_FrontSurface[ 0 ] );
			}
		}

	/* _GetBroadSideBottomLayer() function */
	_3x3RubikCube::_Layer _3x3RubikCube
		::_GetBroadSideBottomLayer( _Surface const& __surface ) const
		{
		_SurfaceType _CurrentSurfaceType = _GetSurfaceType( __surface );

		switch ( _CurrentSurfaceType )
			{
		case _SurfaceType::_Front:  return m_BottomSurface [ 0 ];
		case _SurfaceType::_Rear:   return _GetInvertLayer( m_BottomSurface [ 2 ] );
		case _SurfaceType::_Left:   return _GetInvertLayer( _GetSurfaceLeftLayer( m_BottomSurface ) );
		case _SurfaceType::_Right:  return _GetSurfaceRightLayer( m_BottomSurface );
		case _SurfaceType::_Top:	return m_FrontSurface[ 0 ];
		case _SurfaceType::_Bottom: return _GetInvertLayer( m_RearSurface [ 2 ] );
			}
		}

	/* _GetBroadSideLeftLayer() function */
	_3x3RubikCube::_Layer _3x3RubikCube
		::_GetBroadSideLeftLayer( _Surface const& __surface ) const
		{

		}

	/* _GetBroadSideRightLayer() function */
	_3x3RubikCube::_Layer _3x3RubikCube
		::_GetBroadSideRightLayer( _Surface const& __surface ) const
		{

		}

	/* _GetInvertLayer() function */
	_3x3RubikCube::_Layer _3x3RubikCube
		::_GetInvertLayer( _Layer const& __layer ) const
		{
		_Layer _TempLayer;
		int _Cnt = 0;

		std::for_each( __layer.rbegin()
					 , __layer.rend()
					 , [ &_Cnt, &_TempLayer ]( _Color _Elem )
					 	{ _TempLayer[ _Cnt++ ] = _Elem; }
					 );

		return _TempLayer;
		}

	/* _GetSurfaceType() function */
	_3x3RubikCube::_SurfaceType _3x3RubikCube
		::_GetSurfaceType( _Surface const& __surface ) const
		{
		/* According to the the center block's color 
		 * to determine which is current surface */
		_Color _CentralColor = __surface[ 1 ][ 1 ];

		switch ( _CentralColor )
			{
		case _Color::_Red: 	  return _SurfaceType::_Front;
		case _Color::_Orange: return _SurfaceType::_Rear;
		case _Color::_Blue:   return _SurfaceType::_Left;
		case _Color::_Green:  return _SurfaceType::_Right;
		case _Color::_Yellow: return _SurfaceType::_Top;
		case _Color::_White:  return _SurfaceType::_Bottom;
			}
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