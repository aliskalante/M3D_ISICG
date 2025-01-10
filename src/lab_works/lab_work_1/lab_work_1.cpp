#include "lab_work_1.hpp"
<<<<<<< HEAD
=======
#include "imgui.h"
>>>>>>> a4d137c3975a7b4395253c3714773028d4bbc290
#include "utils/read_file.hpp"
#include <iostream>

namespace M3D_ISICG
{
	const std::string LabWork1::_shaderFolder = "src/lab_works/lab_work_1/shaders/";
<<<<<<< HEAD

	LabWork1::~LabWork1()
	{
		glDeleteVertexArrays( 1, &_vao );
		glDeleteBuffers( 1, &_vbo );
		glDeleteProgram( _program );
=======
	GLuint			  program				  = GL_INVALID_INDEX;
	GLuint			  vbo;
	GLuint			  vao;

	LabWork1::~LabWork1() { glDeleteProgram( program );
		glDeleteBuffers(1, &vbo );
		glDisableVertexArrayAttrib( vao, 0 );
		glDeleteVertexArrays(1 ,&vao );
>>>>>>> a4d137c3975a7b4395253c3714773028d4bbc290
	}

	bool LabWork1::init()
	{
<<<<<<< HEAD
		std::cout << "Initializing LabWork1..." << std::endl;

		glClearColor( 0.8f, 0.8f, 0.8f, 1.0f );

		_vertices = { { -0.5f, 0.5f }, { 0.5f, 0.5f }, { 0.5f, -0.5f } };

		// buffer object
		glCreateBuffers( 1, &_vbo );
		glNamedBufferData( _vbo, sizeof( Vec2f ) * _vertices.size(), _vertices.data(), GL_STATIC_DRAW );

		// shader et le preogramme
		GLuint			  vertexShader		 = glCreateShader( GL_VERTEX_SHADER );
		const std::string vertexShaderSource = readFile( _shaderFolder + "lw1.vert" );
		const char *	  vertexCode		 = vertexShaderSource.c_str();
		glShaderSource( vertexShader, 1, &vertexCode, nullptr );
		glCompileShader( vertexShader );

		GLuint			  fragmentShader	   = glCreateShader( GL_FRAGMENT_SHADER );
		const std::string fragmentShaderSource = readFile( _shaderFolder + "lw1.frag" );
		const char *	  fragmentCode		   = fragmentShaderSource.c_str();
		glShaderSource( fragmentShader, 1, &fragmentCode, nullptr );
		glCompileShader( fragmentShader );

		_program = glCreateProgram();
		glAttachShader( _program, vertexShader );
		glAttachShader( _program, fragmentShader );
		glLinkProgram( _program );

		glDeleteShader( vertexShader );
		glDeleteShader( fragmentShader );

		// Configuration du vertex array
		glCreateVertexArrays( 1, &_vao );
		glEnableVertexArrayAttrib( _vao, 0 );
		glVertexArrayAttribFormat( _vao, 0, 2, GL_FLOAT, GL_FALSE, 0 );
		glVertexArrayVertexBuffer( _vao, 0, _vbo, 0, sizeof( Vec2f ) );
		glVertexArrayAttribBinding( _vao, 0, 0 );

		std::cout << "LabWork1: Initialization completed ." << std::endl;
		return true;
	}

	void LabWork1::render()
	{
		glClear( GL_COLOR_BUFFER_BIT );
		glUseProgram( _program );
		glBindVertexArray( _vao );
		glDrawArrays( GL_TRIANGLES, 0, 3 );
		glBindVertexArray( 0 );
		glUseProgram( 0 );
	}
=======
		std::vector<Vec2f> vect;
		const std::string vertexShaderStr = readFile( _shaderFolder + "lw1.vert" );
		const std::string fragmentShaderStr = readFile( _shaderFolder + "lw1.frag" );
		std::cout << "Initializing lab work 1..." << std::endl;
		GLuint		   vertexShader = glCreateShader( GL_VERTEX_SHADER );
		const GLchar *vSrc			= vertexShaderStr.c_str();

		glShaderSource( vertexShader, 1, &vSrc, NULL );

		
		GLuint		   fragmentShader = glCreateShader( GL_FRAGMENT_SHADER );
		const GLchar *fSrc			  = fragmentShaderStr.c_str();
		glShaderSource( fragmentShader, 1, &fSrc, NULL );

		glCompileShader( fragmentShader );
		glCompileShader( vertexShader );
		GLint compiled;
		glGetShaderiv( vertexShader, GL_COMPILE_STATUS, &compiled );
		
		if ( !compiled )
		{
			GLchar log[ 1024 ];
			glGetShaderInfoLog( vertexShader, sizeof( log ), NULL, log );
			glDeleteShader( vertexShader );
			glDeleteShader( fragmentShader );
			std ::cerr << " Error compiling vertex shader : " << log << std ::endl;
			return false;
		}
		program = glCreateProgram();
		glAttachShader( program,vertexShader );
		glAttachShader( program,fragmentShader );

		glLinkProgram( program );

		GLint linked;
		glGetProgramiv( program, GL_LINK_STATUS, &linked );
		if ( !linked )
		{
			GLchar log[ 1024 ];
			glGetProgramInfoLog( program, sizeof( log ), NULL, log );
			std ::cerr << " Error linking program : " << log << std ::endl;
			return false;
		}

		vect.push_back( Vec2f(0.5f,0.5f) );
		vect.push_back( Vec2f( -0.5f, 0.5f ) );
		vect.push_back( Vec2f( 0.5f, -0.5f ) );

		glCreateBuffers( 1, &vbo );
		glNamedBufferData( vbo, vect.size() * sizeof( Vec2f ), vect.data(), GL_STATIC_DRAW );

		glCreateVertexArrays( 1, &vao );
		glEnableVertexArrayAttrib( vao, 0 );//activer l'attribut avertexposition du vao
		glVertexArrayAttribFormat( vao, 0, 2, GL_FLOAT, GL_FALSE, 0 );
		glVertexArrayVertexBuffer( vao, 0, vbo, 0, sizeof( float ) * 2 );//associer lindex 0 au vbo qui contient les somment pour que 
		//avertexposition prend chque foix un elemnt(sommet) de ce vbo
		glVertexArrayAttribBinding( vao, 0, 0 );


		glDeleteShader( vertexShader );
		glDeleteShader( fragmentShader );
		// Set the color used by glClear to clear the color buffer (in render()).
		glClearColor( _bgColor.x, _bgColor.y, _bgColor.z, _bgColor.w );

		std::cout << "Done!" << std::endl;
		return true;
	}

	void LabWork1::animate( const float p_deltaTime ) {}

	void LabWork1::render() { 
		glClear( GL_COLOR_BUFFER_BIT );
		glUseProgram( program );
		glBindVertexArray( vao );
		glDrawArrays( GL_TRIANGLES, 0, 3 );
		glBindVertexArray( 0 );
	}

	void LabWork1::handleEvents( const SDL_Event & p_event )
	{}

	void LabWork1::displayUI()
	{
		ImGui::Begin( "Settings lab work 1" );
		ImGui::Text( "No setting available!" );
		ImGui::End();
	}

>>>>>>> a4d137c3975a7b4395253c3714773028d4bbc290
} // namespace M3D_ISICG
