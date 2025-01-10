<<<<<<< HEAD
#include "lab_work_2.hpp"
#include "imgui.h"
#include "utils/read_file.hpp"
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
=======
#include "imgui.h"
#include "lab_work_2.hpp"
#include "utils/read_file.hpp"
#include <iostream>
#include <glm/gtc/type_ptr.hpp> 
>>>>>>> a4d137c3975a7b4395253c3714773028d4bbc290

namespace M3D_ISICG
{
	const std::string LabWork2::_shaderFolder = "src/lab_works/lab_work_2/shaders/";
<<<<<<< HEAD

	GLuint	shaderProgram = GL_INVALID_INDEX;
	GLuint	vertexArray, positionBuffer, colorBuffer, indexBuffer;
	GLint	translationUniformLocation, brightnessUniformLocation;
	GLfloat brightness	= 1.0f;
	GLfloat elapsedTime = 0.0f;

	LabWork2::~LabWork2()
	{
		glDeleteVertexArrays( 1, &vertexArray );
		glDeleteBuffers( 1, &positionBuffer );
		glDeleteBuffers( 1, &colorBuffer );
		glDeleteBuffers( 1, &indexBuffer );
		glDeleteProgram( shaderProgram );
=======
	GLuint			  program2				  = GL_INVALID_INDEX;
	GLuint			  vbo2;
	GLuint			  vao2;
	GLuint			  ebo;
	GLuint			  vboCol; 
	GLint			  uTranslationXLocation;
	GLint			  luminositeLocation;
	GLfloat			  time=0.0f;
	GLfloat			  luminosite = 1.0f;
	LabWork2::~LabWork2()
	{
		glDeleteProgram( program2 );
		glDeleteBuffers( 1, &vbo2 );
		glDisableVertexArrayAttrib( vao2, 0 );
		glDeleteVertexArrays( 1, &vao2 );
>>>>>>> a4d137c3975a7b4395253c3714773028d4bbc290
	}

	bool LabWork2::init()
	{
<<<<<<< HEAD
		std::cout << "Starting initialization of LabWork2..." << std::endl;

		glClearColor( 0.8f, 0.8f, 0.8f, 1.0f );

		const std::vector<Vec2f> vertexPositions
			= { { -0.5f, -0.5f }, { 0.5f, -0.5f }, { 0.5f, 0.5f }, { -0.5f, 0.5f } };
		const std::vector<Vec3f> vertexColors
			= { { 1.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f, 1.0f }, { 1.0f, 0.0f, 1.0f } };
		const std::vector<unsigned int> indices = { 0, 1, 2, 0, 2, 3 };

		// charger et compiler les shaders
		const std::string vertexShaderCode	 = readFile( _shaderFolder + "lw2.vert" );
		const std::string fragmentShaderCode = readFile( _shaderFolder + "lw2.frag" );

		GLuint		 vertexShader = glCreateShader( GL_VERTEX_SHADER );
		const char * vertexSource = vertexShaderCode.c_str();
		glShaderSource( vertexShader, 1, &vertexSource, nullptr );
		glCompileShader( vertexShader );

		GLuint		 fragmentShader = glCreateShader( GL_FRAGMENT_SHADER );
		const char * fragmentSource = fragmentShaderCode.c_str();
		glShaderSource( fragmentShader, 1, &fragmentSource, nullptr );
		glCompileShader( fragmentShader );

		shaderProgram = glCreateProgram();
		glAttachShader( shaderProgram, vertexShader );
		glAttachShader( shaderProgram, fragmentShader );
		glLinkProgram( shaderProgram );

		glDeleteShader( vertexShader );
		glDeleteShader( fragmentShader );

		// Creation des buffers
		glCreateBuffers( 1, &positionBuffer );
		glNamedBufferData(
			positionBuffer, vertexPositions.size() * sizeof( Vec2f ), vertexPositions.data(), GL_STATIC_DRAW );

		glCreateBuffers( 1, &colorBuffer );
		glNamedBufferData( colorBuffer, vertexColors.size() * sizeof( Vec3f ), vertexColors.data(), GL_STATIC_DRAW );

		glCreateBuffers( 1, &indexBuffer );
		glNamedBufferData( indexBuffer, indices.size() * sizeof( unsigned int ), indices.data(), GL_STATIC_DRAW );

		// vertex array
		glCreateVertexArrays( 1, &vertexArray );

		glVertexArrayVertexBuffer( vertexArray, 0, positionBuffer, 0, sizeof( Vec2f ) );
		glVertexArrayAttribFormat( vertexArray, 0, 2, GL_FLOAT, GL_FALSE, 0 );
		glEnableVertexArrayAttrib( vertexArray, 0 );
		glVertexArrayAttribBinding( vertexArray, 0, 0 );

		glVertexArrayVertexBuffer( vertexArray, 1, colorBuffer, 0, sizeof( Vec3f ) );
		glVertexArrayAttribFormat( vertexArray, 1, 3, GL_FLOAT, GL_FALSE, 0 );
		glEnableVertexArrayAttrib( vertexArray, 1 );
		glVertexArrayAttribBinding( vertexArray, 1, 1 );

		glVertexArrayElementBuffer( vertexArray, indexBuffer );

		translationUniformLocation = glGetUniformLocation( shaderProgram, "uTranslationX" );
		brightnessUniformLocation  = glGetUniformLocation( shaderProgram, "luminosite" );

		glProgramUniform1f( shaderProgram, translationUniformLocation, 0.0f );
		glProgramUniform1f( shaderProgram, brightnessUniformLocation, brightness );

		std::cout << "LabWork2 initialization complete!" << std::endl;
		return true;
	}

	void LabWork2::animate( const float deltaTime )
	{
		elapsedTime += deltaTime;

		// maj translation par temps
		float translationX = 0.5f * glm::sin( elapsedTime );
		glProgramUniform1f( shaderProgram, translationUniformLocation, translationX );
=======
		std::vector<Vec2f> vect;
		std::vector<int>   vect_indice;
		std::vector<float> vect_couleur;
		const std::string  vertexShaderStr	 = readFile( _shaderFolder + "lw2.vert" );
		const std::string  fragmentShaderStr = readFile( _shaderFolder + "lw2.frag" );
		std::cout << "Initializing lab work 2..." << std::endl;
		GLuint		   vertexShader = glCreateShader( GL_VERTEX_SHADER );
		const GLchar * vSrc			= vertexShaderStr.c_str();

		glShaderSource( vertexShader, 1, &vSrc, NULL );

		GLuint		   fragmentShader = glCreateShader( GL_FRAGMENT_SHADER );
		const GLchar * fSrc			  = fragmentShaderStr.c_str();
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
		program2 = glCreateProgram();
		glAttachShader( program2, vertexShader );
		glAttachShader( program2, fragmentShader );

		glLinkProgram( program2 );

		GLint linked;
		glGetProgramiv( program2, GL_LINK_STATUS, &linked );
		if ( !linked )
		{
			GLchar log[ 1024 ];
			glGetProgramInfoLog( program2, sizeof( log ), NULL, log );
			std ::cerr << " Error linking program : " << log << std ::endl;
			return false;
		}

		vect.push_back( Vec2f( 0.5f, 0.5f ) );
		vect.push_back( Vec2f( -0.5f, 0.5f ) );
		vect.push_back( Vec2f( -0.5f, -0.5f ) );
		vect.push_back( Vec2f( 0.5f, -0.5f ) );

		glCreateBuffers( 1, &vbo2 );
		glNamedBufferData( vbo2, vect.size() * sizeof( Vec2f ), vect.data(), GL_STATIC_DRAW );

		glCreateVertexArrays( 1, &vao2 );
		glEnableVertexArrayAttrib( vao2, 0 ); // activer l'attribut avertexposition du vao
		glVertexArrayAttribFormat( vao2, 0, 2, GL_FLOAT, GL_FALSE, 0 );
		glVertexArrayVertexBuffer(vao2, 0, vbo2, 0, sizeof( float ) * 2 ); // associer lindex 0 au vbo qui contient les somment pour que
		// avertexposition prend chque foix un elemnt(sommet) de ce vbo
		glVertexArrayAttribBinding( vao2, 0, 0 );
		
		vect_indice.push_back( 0 );
		vect_indice.push_back( 1 );
		vect_indice.push_back( 2 );

		
		vect_indice.push_back( 3 );
		vect_indice.push_back( 2 );

		glCreateBuffers( 1, &ebo );
		glNamedBufferData( ebo, vect_indice.size() * sizeof( int ), vect_indice.data(), GL_STATIC_DRAW );
		glVertexArrayElementBuffer( vao2, ebo );


		vect_couleur = { 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f };
		glCreateBuffers( 1, &vboCol );
		glNamedBufferData( vboCol, vect_couleur.size() * sizeof( float ), vect_couleur.data(), GL_STATIC_DRAW );
		glEnableVertexArrayAttrib( vao2, 1 ); 
		glVertexArrayAttribFormat( vao2, 1, 3, GL_FLOAT, GL_FALSE, 0 );
		glVertexArrayVertexBuffer( vao2, 1, vbo2, 0, sizeof( float ) * 3 );
		glVertexArrayAttribBinding( vao2, 1, 1 );
		
		
	 uTranslationXLocation = glGetUniformLocation( program2, "uTranslationX" );
		// Valeur arbitraire pour la translation, ici on choisit 0.2f
		glProgramUniform1f( program2, uTranslationXLocation, 0.2f );

		luminositeLocation = glGetUniformLocation( program2, "luminosite" );

		// Initialiser la luminosité
		glProgramUniform1f( program2,luminositeLocation, luminosite );
		
		glDeleteShader( vertexShader );
		glDeleteShader( fragmentShader );
		// Set the color used by glClear to clear the color buffer (in render()).
		glClearColor( _bgColor.x, _bgColor.y, _bgColor.z, _bgColor.w );

		std::cout << "Done!" << std::endl;
		return true;
	}

	void LabWork2::animate( const float p_deltaTime ) {
		// Mettre à jour le temps total
		time += p_deltaTime;

		// Calculer une valeur entre -0.5 et 0.5 avec la fonction sin
		float translationX = 0.5f * glm::sin( time );

		// Assigner cette valeur à la variable uniform uTranslationX
		glProgramUniform1f( program2, uTranslationXLocation, translationX );
>>>>>>> a4d137c3975a7b4395253c3714773028d4bbc290
	}

	void LabWork2::render()
	{
		glClear( GL_COLOR_BUFFER_BIT );
<<<<<<< HEAD
		glUseProgram( shaderProgram );
		glBindVertexArray( vertexArray );
		glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0 );
		glBindVertexArray( 0 );
		glUseProgram( 0 );
	}

	void LabWork2::handleEvents( const SDL_Event & event ) {}

	void LabWork2::displayUI()
	{
		ImGui::Begin( "Lab Work 2 Settings" );
		if ( ImGui::SliderFloat( "Brightness", &brightness, 0.0f, 1.0f ) )
		{
			glProgramUniform1f( shaderProgram, brightnessUniformLocation, brightness );
		}
		ImGui::End();
	}
=======
		glUseProgram( program2 );
		glBindVertexArray( vao2 );
		glDrawElements( GL_TRIANGLES	, 6, GL_UNSIGNED_INT, 0 );
		glBindVertexArray( 0 );
	}

	void LabWork2::handleEvents( const SDL_Event & p_event ) {}

	void LabWork2::displayUI()
	{
		ImGui::Begin( "Settings lab work 1" );
		// Créer un slider pour la luminosité (de 0 à 1)
		if ( ImGui::SliderFloat( "luminosite", &luminosite, 0.0f, 1.0f ) )
		{
			// Si la luminosité est modifiée, mettre à jour l'uniform dans le shader
			glProgramUniform1f( program2, luminositeLocation, luminosite );
		}

		// Palette de couleurs pour la couleur de fond
		if ( ImGui::ColorEdit3( "Background Color", glm::value_ptr( _bgColor ) ) )
		{
			// Mettre à jour la couleur de fond OpenGL
			glClearColor( _bgColor.x, _bgColor.y, _bgColor.z, _bgColor.w );
		}
		ImGui::End();
	}

>>>>>>> a4d137c3975a7b4395253c3714773028d4bbc290
} // namespace M3D_ISICG
