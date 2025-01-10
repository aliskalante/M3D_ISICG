#include "lab_work_4.hpp"
#include "utils/read_file.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <imgui.h>
#include <iostream>

namespace M3D_ISICG
{
	bool LabWork4::init()
	{
		std::cout << "Initializing LabWork4..." << std::endl;

		_camera.setPosition( glm::vec3( 0.0f, 0.0f, 5.0f ) );
		_camera.setLookAt( glm::vec3( 0.0f, 0.0f, 0.0f ) );
		_camera.setScreenSize( 1280, 720 );

		const std::string vertexShaderStr	= readFile( "src/lab_works/lab_work_4/shaders/lw4.vert" );
		const std::string fragmentShaderStr = readFile( "src/lab_works/lab_work_4/shaders/lw4.frag" );

		GLuint		 vertexShader = glCreateShader( GL_VERTEX_SHADER );
		const char * vSrc		  = vertexShaderStr.c_str();
		glShaderSource( vertexShader, 1, &vSrc, NULL );
		glCompileShader( vertexShader );

		GLuint		 fragmentShader = glCreateShader( GL_FRAGMENT_SHADER );
		const char * fSrc			= fragmentShaderStr.c_str();
		glShaderSource( fragmentShader, 1, &fSrc, NULL );
		glCompileShader( fragmentShader );

		_program = glCreateProgram();
		glAttachShader( _program, vertexShader );
		glAttachShader( _program, fragmentShader );
		glLinkProgram( _program );

		glDeleteShader( vertexShader );
		glDeleteShader( fragmentShader );

		_bunnyModel.load( "bunny", "data/models/bunny.obj" );
		_bunnyModel.setupGL();

		//_conferenceModel.load( "bunny", "data/models/conference.obj" );
		//_conferenceModel.setupGL();

		glUseProgram( _program );
		glEnable( GL_DEPTH_TEST );

		std::cout << "Done!" << std::endl;
		return true;
	}

	void LabWork4::render()
	{
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

		// Matrice

		glm::mat4 viewMatrix	   = _camera.getViewMatrix();
		glm::mat4 projectionMatrix = _camera.getProjectionMatrix();
		glm::mat4 modelMatrix	   = glm::mat4( 1.0f );
		// glm::mat4 modelMatrix  = glm::scale( glm::mat4( 1.f ), glm::vec3( 0.003f ) );
		glm::mat4 mvpMatrix	   = projectionMatrix * viewMatrix * modelMatrix;
		glm::mat3 normalMatrix = glm::transpose( glm::inverse( glm::mat3( modelMatrix ) ) );

		glUseProgram( _program );

		glUniformMatrix4fv( glGetUniformLocation( _program, "uMVPMatrix" ), 1, GL_FALSE, glm::value_ptr( mvpMatrix ) );
		glUniformMatrix4fv(
			glGetUniformLocation( _program, "uModelMatrix" ), 1, GL_FALSE, glm::value_ptr( modelMatrix ) );
		glUniformMatrix3fv(
			glGetUniformLocation( _program, "uNormalMatrix" ), 1, GL_FALSE, glm::value_ptr( normalMatrix ) );

		glm::vec3 cameraPos = _camera.getPosition();
		glUniform3fv( glGetUniformLocation( _program, "uCameraPosition" ), 1, glm::value_ptr( cameraPos ) );

		glUniform3fv(
			glGetUniformLocation( _program, "uAmbientColor" ), 1, glm::value_ptr( glm::vec3( 0.1f, 0.1f, 0.1f ) ) );
		glUniform3fv(
			glGetUniformLocation( _program, "uDiffuseColor" ), 1, glm::value_ptr( glm::vec3( 0.0f, 0.8f, 0.8f ) ) );
		glUniform3fv(
			glGetUniformLocation( _program, "uSpecularColor" ), 1, glm::value_ptr( glm::vec3( 1.0f, 1.0f, 1.0f ) ) );
		glUniform3fv(
			glGetUniformLocation( _program, "uLightDirection" ), 1, glm::value_ptr( glm::vec3( 1.0f, 1.0f, -1.0f ) ) );
		glUniform1f( glGetUniformLocation( _program, "uShininess" ), 32.0f );

		_bunnyModel.render( _program );
		//_conferenceModel.render( _program );

		glUseProgram( 0 );
	}

	void LabWork4::displayUI()
	{
		ImGui::Begin( "Settings Lab Work 4" );

		ImGui::End();
	}

	void LabWork4::handleEvents( const SDL_Event & p_event ) {}
} // namespace M3D_ISICG
