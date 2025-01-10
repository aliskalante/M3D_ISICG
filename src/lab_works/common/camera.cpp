#include "camera.hpp"
<<<<<<< HEAD
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>
=======
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/string_cast.hpp"
>>>>>>> a4d137c3975a7b4395253c3714773028d4bbc290
#include <iostream>

namespace M3D_ISICG
{
	Camera::Camera()
	{
<<<<<<< HEAD
		_updateViewMatrix();
		_updateProjectionMatrix();
	}

	const glm::mat4 & Camera::getViewMatrix() const { return _viewMatrix; }

	const glm::mat4 & Camera::getProjectionMatrix() const { return _projectionMatrix; }

	void Camera::setPosition( const glm::vec3 & newPosition )
	{
		_position = newPosition;
		_updateViewMatrix();
	}

	void Camera::setLookAt( const glm::vec3 & target )
	{
		_invDirection = glm::normalize( _position - target );
		_pitch		  = glm::clamp( glm::degrees( glm::asin( _invDirection.y ) ), -89.f, 89.f );
		_yaw		  = glm::degrees( glm::atan( _invDirection.z, _invDirection.x ) );
		_recalculateVectors();
	}

	void Camera::setFovy( float newFovy )
	{
		_fovy = newFovy;
		_updateProjectionMatrix();
	}

	void Camera::setScreenSize( int width, int height )
	{
		_screenWidth  = width;
		_screenHeight = height;
		_aspectRatio  = static_cast<float>( _screenWidth ) / _screenHeight;
		_updateProjectionMatrix();
	}

	void Camera::moveFront( float delta )
	{
		_position -= _invDirection * delta;
		_updateViewMatrix();
	}

	void Camera::moveRight( float delta )
	{
		_position += _right * delta;
		_updateViewMatrix();
	}

	void Camera::moveUp( float delta )
	{
		_position += _up * delta;
		_updateViewMatrix();
	}

	void Camera::rotate( float deltaYaw, float deltaPitch )
	{
		_yaw   = glm::mod( _yaw + deltaYaw, 360.f );
		_pitch = glm::clamp( _pitch + deltaPitch, -89.f, 89.f );
		_recalculateVectors();
=======
		_computeViewMatrix();
		_computeProjectionMatrix();
	}

	void Camera::setPosition( const Vec3f & p_position )
	{
		_position = p_position;
		_computeViewMatrix();
	}

	void Camera::setLookAt( const Vec3f & p_lookAt )
	{
		_invDirection = glm::normalize( _position - p_lookAt );
		_pitch		  = glm::clamp( glm::degrees( glm::asin( _invDirection.y ) ), -89.f, 89.f );
		_yaw		  = glm::degrees( glm::atan( _invDirection.z, _invDirection.x ) );
		_updateVectors();
	}

	void Camera::setFovy( const float p_fovy )
	{
		_fovy = p_fovy;
		_computeProjectionMatrix();
	}

	void Camera::setScreenSize( const int p_width, const int p_height )
	{
		_screenWidth  = p_width;
		_screenHeight = p_height;
		_aspectRatio  = float( _screenWidth ) / _screenHeight;
		_updateVectors();
		_computeViewMatrix();
		_computeProjectionMatrix();
	}

	void Camera::moveFront( const float p_delta )
	{
		_position -= _invDirection * p_delta;
		_computeViewMatrix();
	}

	void Camera::moveRight( const float p_delta )
	{
		_position += _right * p_delta;
		_computeViewMatrix();
	}

	void Camera::moveUp( const float p_delta )
	{
		_position += _up * p_delta;
		_computeViewMatrix();
	}

	void Camera::rotate( const float p_yaw, const float p_pitch )
	{
		_yaw   = glm::mod( _yaw + p_yaw, 360.f );
		_pitch = glm::clamp( _pitch + p_pitch, -89.f, 89.f );
		_updateVectors();
>>>>>>> a4d137c3975a7b4395253c3714773028d4bbc290
	}

	void Camera::print() const
	{
<<<<<<< HEAD
		std::cout << "======= Camera Info =======" << std::endl;
		std::cout << "Position: " << glm::to_string( _position ) << std::endl;
		std::cout << "Direction: " << glm::to_string( -_invDirection ) << std::endl;
		std::cout << "Right Vector: " << glm::to_string( _right ) << std::endl;
		std::cout << "Up Vector: " << glm::to_string( _up ) << std::endl;
		std::cout << "Yaw: " << _yaw << " degrees" << std::endl;
		std::cout << "Pitch: " << _pitch << " degrees" << std::endl;
		std::cout << "===========================" << std::endl;
	}

	void Camera::_updateViewMatrix()
	{
		_viewMatrix = glm::lookAt( _position,				  // Position actuelle
								   _position - _invDirection, // Point regardé
								   _up						  // Direction "haut"
		);
	}

	void Camera::_updateProjectionMatrix()
	{
		_projectionMatrix = glm::perspective( glm::radians( _fovy ), // Champ de vision
											  _aspectRatio,			 // Rapport largeur/hauteur
											  0.1f,					 // Plan proche
											  100.0f				 // Plan lointain
		);
	}

	void Camera::_recalculateVectors()
	{
		const float yawRadians	 = glm::radians( _yaw );
		const float pitchRadians = glm::radians( _pitch );
		_invDirection			 = glm::normalize( glm::vec3( glm::cos( yawRadians ) * glm::cos( pitchRadians ),
													  glm::sin( pitchRadians ),
													  glm::sin( yawRadians ) * glm::cos( pitchRadians ) ) );

		_right = glm::normalize(
			glm::cross( glm::vec3( 0.f, 1.f, 0.f ), _invDirection ) ); // Utilisation de l'axe Y comme "up".
		_up = glm::normalize( glm::cross( _invDirection, _right ) );

		_updateViewMatrix();
=======
		std::cout << "======== Camera ========" << std::endl;
		std::cout << "Position: " << glm::to_string( _position ) << std::endl;
		std::cout << "View direction: " << glm::to_string( -_invDirection ) << std::endl;
		std::cout << "Right: " << glm::to_string( _right ) << std::endl;
		std::cout << "Up: " << glm::to_string( _up ) << std::endl;
		std::cout << "Yaw: " << _yaw << std::endl;
		std::cout << "Pitch: " << _pitch << std::endl;
		std::cout << "========================" << std::endl;
	}

	void Camera::_computeViewMatrix()
	{ 
	}

	void Camera::_computeProjectionMatrix()
	{
	}

	void Camera::_updateVectors()
	{
		const float yaw	  = glm::radians( _yaw );
		const float pitch = glm::radians( _pitch );
		_invDirection	  = glm::normalize(
			Vec3f( glm::cos( yaw ) * glm::cos( pitch ), glm::sin( pitch ), glm::sin( yaw ) * glm::cos( pitch ) ) );
		_right = glm::normalize( glm::cross( Vec3f( 0.f, 1.f, 0.f ), _invDirection ) ); // We suppose 'y' as world up.
		_up	   = glm::normalize( glm::cross( _invDirection, _right ) );

		_computeViewMatrix();
>>>>>>> a4d137c3975a7b4395253c3714773028d4bbc290
	}

} // namespace M3D_ISICG
