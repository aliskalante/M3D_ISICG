#ifndef __TRIANGLE_MESH_HPP__
#define __TRIANGLE_MESH_HPP__

#include "GL/gl3w.h"
#include "define.hpp"
#include <iostream>
#include <vector>

namespace M3D_ISICG
{
	struct Vertex
	{
<<<<<<< HEAD
		Vec3f _position; 
		Vec3f _normal;	  
		Vec2f _texCoords; 
		Vec3f _tangent;	  
		Vec3f _bitangent; 
=======
		Vec3f _position;
		Vec3f _normal;
		Vec2f _texCoords;
		Vec3f _tangent;
		Vec3f _bitangent;
>>>>>>> a4d137c3975a7b4395253c3714773028d4bbc290
	};

	struct Texture
	{
<<<<<<< HEAD
		unsigned int _id;	
		std::string	 _type; 
		std::string	 _path; 
=======
		unsigned int _id;
		std::string	 _type;
		std::string	 _path;
>>>>>>> a4d137c3975a7b4395253c3714773028d4bbc290
	};

	struct Material
	{
<<<<<<< HEAD
		Vec3f _ambient	 = VEC3F_ZERO; 
		Vec3f _diffuse	 = VEC3F_ZERO; 
		Vec3f _specular	 = VEC3F_ZERO; 
		float _shininess = 0.f;		   

		bool _hasAmbientMap	  = false; 
		bool _hasDiffuseMap	  = false; 
		bool _hasSpecularMap  = false; 
		bool _hasShininessMap = false; 

		Texture _ambientMap;   
		Texture _diffuseMap;   
		Texture _specularMap;  
		Texture _shininessMap; 
=======
		Vec3f _ambient	 = VEC3F_ZERO;
		Vec3f _diffuse	 = VEC3F_ZERO;
		Vec3f _specular	 = VEC3F_ZERO;
		float _shininess = 0.f;

		bool _hasAmbientMap	  = false;
		bool _hasDiffuseMap	  = false;
		bool _hasSpecularMap  = false;
		bool _hasShininessMap = false;

		Texture _ambientMap;
		Texture _diffuseMap;
		Texture _specularMap;
		Texture _shininessMap;
>>>>>>> a4d137c3975a7b4395253c3714773028d4bbc290
	};

	class TriangleMesh
	{
	  public:
<<<<<<< HEAD
		TriangleMesh() = delete; 
=======
		TriangleMesh() = delete;
>>>>>>> a4d137c3975a7b4395253c3714773028d4bbc290
		TriangleMesh( const std::string &				p_name,
					  const std::vector<Vertex> &		p_vertices,
					  const std::vector<unsigned int> & p_indices,
					  const Material &					p_material );

<<<<<<< HEAD
		~TriangleMesh() = default; 

		
		void render( const GLuint p_glProgram ) const;

		
		void cleanGL();

		
		void setupGL();

	  private:
		glm::mat3 _normalMatrix;   
		glm::vec3 _lightDirection; 

	  public:
		std::string _name = "Unknown"; 

		// ================ Données géométriques
		std::vector<Vertex>		  _vertices; // Liste des sommets
		std::vector<unsigned int> _indices;	 // Liste des indices

		// ================ Données de matériau
		Material _material; // Matériau du maillage

		// ================ Données OpenGL
=======
		~TriangleMesh() = default;

		void render( const GLuint p_glProgram ) const;

		void cleanGL();

	  private:
		void _setupGL();

	  public:
		std::string _name = "Unknown";

		// ================ Geometric data.
		std::vector<Vertex>		  _vertices;
		std::vector<unsigned int> _indices;

		// ================ Material data.
		Material _material;

		// ================ GL data.
>>>>>>> a4d137c3975a7b4395253c3714773028d4bbc290
		GLuint _vao = GL_INVALID_INDEX; // Vertex Array Object
		GLuint _vbo = GL_INVALID_INDEX; // Vertex Buffer Object
		GLuint _ebo = GL_INVALID_INDEX; // Element Buffer Object
	};
} // namespace M3D_ISICG

#endif // __TRIANGLE_MESH_HPP__
