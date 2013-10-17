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

#include "AbstractRubikCube.hxx"

#include <array>
#include <initializer_list>

/* _3x3RubikCube class definition.
 * This class is inherites from _AbstractRubikCube by public */
class _3x3RubikCube : public _AbstractRubikCube
	{
public:
	_3x3RubikCube( std::initializer_list< _Color > const& _Front
				 , std::initializer_list< _Color > const& _Rear
				 , std::initializer_list< _Color > const& _Left
				 , std::initializer_list< _Color > const& _Right
				 , std::initializer_list< _Color > const& _Top
				 , std::initializer_list< _Color > const& _Bottom
				 );

	enum class _SurfaceType { _Front, _Rear
							, _Left, _Right
							, _Top, _Bottom
							};

	// virtual ~_3x3RubikCube() { ; }

	virtual _OperationMakers _SolveRubikCube() override;
	virtual void _Print() const override;

private:
	enum { _Oders = 3 };

 	using _Layer = std::array< _Color, _Oders >;

	virtual void 
	_InitializeSurface( std::initializer_list< _Color > const&
	 				  , _Surface& ) override;

	virtual void 
	_PrintSpecifiedSurface( _Surface const&
						  , std::string const& _PlaceHolder = "" ) const override;

	virtual void
	_PrintSpecifiedLayer( _Surface const& , int
						, std::string const& _PlaceHolder = "" ) const override;

	void _PrintLayer( std::array< _Color, _Oders > const& _Layer ) const;

	// Rubik cubes' basic operational functions.
	virtual void
	_RevoleSpecifiedSurface( _Surface&
						   , _RevoleDirection
						   , _RevoleDegree _Degree = _RevoleDegree::_90Degree ) override;

	/* Front surface */
	virtual void 
	_FrontSurface_Left( _RevoleDegree _Degree = _RevoleDegree::_90Degree ) override;
	virtual void 
	_FrontSurface_Right( _RevoleDegree _Degree = _RevoleDegree::_90Degree ) override;

	/* Rear surface */
	virtual void 
	_RearSurface_Left( _RevoleDegree _Degree = _RevoleDegree::_90Degree ) override;
	virtual void 
	_RearSurface_Right( _RevoleDegree _Degree = _RevoleDegree::_90Degree ) override;

	/* Left surface */
	virtual void 
	_LeftSurface_Forward( _RevoleDegree _Degree = _RevoleDegree::_90Degree ) override;
	virtual void 
	_LeftSurface_Backward( _RevoleDegree _Degree = _RevoleDegree::_90Degree ) override;

	/* Right surface */
	virtual void 
	_RightSurface_Forward( _RevoleDegree _Degree = _RevoleDegree::_90Degree ) override;
	virtual void 
	_RightSurface_Backward( _RevoleDegree _Degree = _RevoleDegree::_90Degree ) override;

	/* Top surface */
	virtual void 
	_TopSurface_Left( _RevoleDegree _Degree = _RevoleDegree::_90Degree ) override;
	virtual void 
	_TopSurface_Right( _RevoleDegree _Degree = _RevoleDegree::_90Degree ) override;

	/* Bottom surface */
	virtual void 
	_BottomSurface_Left( _RevoleDegree _Degree = _RevoleDegree::_90Degree ) override;
	virtual void 
	_BottomSurface_Right( _RevoleDegree _Degree = _RevoleDegree::_90Degree ) override;

	// Rotate 90 degree.
	virtual void
	_RotateLeft90Degree( _Surface& __surface ) override;

	virtual void
	_RotateForward90Degree( _Surface& __surface ) override
		{ _RotateLeft90Degree( __surface ); }

	virtual void
	_RotateRight90Degree( _Surface& __surface ) override;

	virtual void
	_RotateBackward90Degree( _Surface& __surface ) override
		{ _RotateRight90Degree( __surface ); }

	// Rotate 180 degree.
	virtual void
	_RotateLeft180Degree( _Surface& __surface ) override;

	virtual void
	_RotateForward180Degree( _Surface& __surface ) override
		{ _RotateLeft180Degree( __surface ); }

	virtual void
	_RotateRight180Degree( _Surface& __surface ) override;

	virtual void
	_RotateBackward180Degree( _Surface& __surface ) override
		{ _RotateRight180Degree( __surface ); }

	// Rotate 90 degree.
	virtual void
	_RotateLeft270Degree( _Surface& __surface ) override;

	virtual void
	_RotateForward270Degree( _Surface& __surface ) override
		{ _RotateLeft270Degree( __surface ); }

	virtual void
	_RotateRight270Degree( _Surface& __surface ) override;

	virtual void
	_RotateBackward270Degree( _Surface& __surface ) override
		{ _RotateRight270Degree( __surface ); }

	_Layer _GetSurfaceTopLayer( _Surface const& )    const;
	_Layer _GetSurfaceBottomLayer( _Surface const& ) const;
	_Layer _GetSurfaceLeftLayer( _Surface const& )   const;
	_Layer _GetSurfaceRightLayer( _Surface const& )  const;

	_Layer _GetBroadSideTopLayer( _Surface const& )    const;
	_Layer _GetBroadSideBottomLayer( _Surface const& ) const;
	_Layer _GetBroadSideLeftLayer( _Surface const& )   const;
	_Layer _GetBroadSideRightLayer( _Surface const& )  const;

	_Layer _GetInvertLayer( _Layer const& ) const;

	_SurfaceType _GetSurfaceType( _Surface const& ) const;

	_Surface m_FrontSurface;
	_Surface m_RearSurface;
	_Surface m_LeftSurface;
	_Surface m_RightSurface;
	_Surface m_TopSurface;
	_Surface m_BottomSurface;

public:
	_Layer _Test() const
		{ return _GetBroadSideBottomLayer( m_LeftSurface ); }
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