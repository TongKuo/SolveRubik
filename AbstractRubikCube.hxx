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

_Pragma ( "once" );

#include <queue>
#include <functional>

/* _AbstractRubikCube class definition and implementation
 * This class is an abstract base class.
 * All the rubik classes are inherited from it. */
class _AbstractRubikCube
	{
public:
	// virtual ~_AbstractRubikCube() { ; }

	// Rubik cubes' basic operational markers.
	enum class _RevoleOperation 
		{
		  _FrontSurfaceLeft_90Deg = 0x11d90, _FrontSurfaceLeft_180Deg = 0x11d180
		, _FrontSurfaceLeft_270Deg = 0x11d270

		, _FrontSurfaceRight_90Deg = 0x12d90, _FrontSurfaceRight_180Deg = 0x12d180
		, _FrontSurfaceRight_270Deg = 0x12d270

		, _RearSurfaceLeft_90Deg = 0x21d90, _RearSurfaceLeft_180Deg = 0x21d180
		, _RearSurfaceLeft_279Deg = 0x21d270

		, _RearSurfaceRight_90Deg = 0x22d90, _RearSurfaceRight_180Deg = 0x22d180
		, _RearSurfaceRight_270Deg = 0x22d270

		, _LeftSurfaceForward_90Deg = 0x31d90, _LeftSurfaceForward_180Deg = 0x31d180
		, _LeftSurfaceForward_270Deg = 0x31d270

		, _LeftSurfaceBackward_90Deg = 0x32d90, _LeftSurfaceBackward_180Deg = 0x32d180
		, _LeftSurfaceBackward_270Deg = 0x32d270

		, _RightSurfaceForward_90Deg = 0x41d90, _RightSurfaceForward_180Deg = 0x41d180
		, _RightSurfaceForward_270Deg = 0x41d270

		, _RightSurfaceBackward_90Deg = 0x42d90, _RightSurfaceBackward_180Deg = 0x42d180
		, _RightSurfaceBackward_270 = 0x42d270

		, _TopSurfaceLeft_90Deg = 0x51d90, _TopSurfaceLeft_180Deg = 0x51d180
		, _TopSurfaceLeft_270Deg = 0x51d270

		, _TopSurfaceRight_90Deg = 0x52d90, _TopSurfaceRight_180Deg = 0x52d180
		, _TopSurfaceRight_270Deg = 0x52d270

		, _BottomSurfaceLeft_90Deg = 0x61d90, _BottomSurfaceLeft_180Deg = 0x61d180
		, _BottomSurfaceLeft_270Deg = 0x61d270

		, _BottomSurfaceRight_90Deg = 0x62d90, _BottomSurfaceRight_180Deg = 0x62d180
		, _BottomSurfaceRight_270Deg = 0x62d270
		};

	// Rubik cubes' rovole degree, 360degree is insignificant.
	enum class _RevoleDegree { _90Degree = 0xd90, _180Degree = 0xd180
							 , _270Degree = 0xd270 
							 };

	// Rubik cubes' direction of rotation.
	enum class _RevoleDirection { _Left, _Right
							    , _Forward = 0, _Backward = 1
								};

	// Rubik cubes' colors.
	enum class _Color { _Red = 0xFF0000, _Orange = 0x99CC00
					  , _Blue = 0x0000FF, _Green = 0x008000
					  , _Yellow = 0xFFFF00, _White = 0XFFFFFF
					  };

	using _OperationMakers = std::queue< _RevoleOperation >;
	using _OperationFunctions = std::queue< std::function< void ( _RevoleDegree ) > >;

	virtual _OperationMakers _SolveRubikCube() = 0;
	virtual void _Print() const = 0;

protected:
	using _Surface = std::array< std::array< _Color, 3 >, 3 >; 

private:
	virtual void 
	_InitializeSurface( std::initializer_list< _Color > const&
					  , _Surface&) = 0;

	virtual void 
	_PrintSpecifiedSurface( _Surface const&
						  , std::string const& _PlaceHolder = "" ) const = 0;

	virtual void
	_PrintSpecifiedLayer( _Surface const& , int
						, std::string const& _PlaceHolder = "" ) const = 0;

	// Rubik cubes' basic operational functions.
	virtual void
	_RevoleSpecifiedSurface( _Surface&
						   , _RevoleDirection
						   , _RevoleDegree _Degree = _RevoleDegree::_90Degree ) = 0;

	/* Front surface */
	virtual void 
	_FrontSurface_Left( _RevoleDegree _Degree = _RevoleDegree::_90Degree ) = 0;
	virtual void 
	_FrontSurface_Right( _RevoleDegree _Degree = _RevoleDegree::_90Degree ) = 0;

	/* Rear surface */
	virtual void 
	_RearSurface_Left( _RevoleDegree _Degree = _RevoleDegree::_90Degree )  = 0;
	virtual void 
	_RearSurface_Right( _RevoleDegree _Degree = _RevoleDegree::_90Degree ) = 0;

	/* Left surface */
	virtual void 
	_LeftSurface_Forward( _RevoleDegree _Degree = _RevoleDegree::_90Degree)  = 0;
	virtual void 
	_LeftSurface_Backward( _RevoleDegree _Degree = _RevoleDegree::_90Degree ) = 0;

	/* Right surface */
	virtual void 
	_RightSurface_Forward( _RevoleDegree _Degree = _RevoleDegree::_90Degree )  = 0;
	virtual void 
	_RightSurface_Backward( _RevoleDegree _Degree = _RevoleDegree::_90Degree ) = 0;

	/* Top surface */
	virtual void 
	_TopSurface_Left( _RevoleDegree _Degree = _RevoleDegree::_90Degree )  = 0;
	virtual void 
	_TopSurface_Right( _RevoleDegree _Degree = _RevoleDegree::_90Degree ) = 0;

	/* Bottom surface */
	virtual void 
	_BottomSurface_Left( _RevoleDegree _Degree = _RevoleDegree::_90Degree )  = 0;
	virtual void 
	_BottomSurface_Right( _RevoleDegree _Degree = _RevoleDegree::_90Degree ) = 0;

	// Rotate 90 degree.
	virtual void
	_RotateLeft90Degree( _Surface& __surface ) = 0;

	virtual void
	_RotateForward90Degree( _Surface& __surface ) = 0;

	virtual void
	_RotateRight90Degree( _Surface& __surface ) = 0;

	virtual void
	_RotateBackward90Degree( _Surface& __surface ) = 0;

	// Rotate 180 degree.
	virtual void
	_RotateLeft180Degree( _Surface& __surface ) = 0;

	virtual void
	_RotateForward180Degree( _Surface& __surface ) = 0;

	virtual void
	_RotateRight180Degree( _Surface& __surface ) = 0;

	virtual void
	_RotateBackward180Degree( _Surface& __surface ) = 0;

	// Rotate 90 degree.
	virtual void
	_RotateLeft270Degree( _Surface& __surface ) = 0;

	virtual void
	_RotateForward270Degree( _Surface& __surface ) = 0;

	virtual void
	_RotateRight270Degree( _Surface& __surface ) = 0;

	virtual void
	_RotateBackward270Degree( _Surface& __surface ) = 0;

	_OperationMakers 	m_OperationMarkers;
	_OperationFunctions m_OperationFunctions;
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