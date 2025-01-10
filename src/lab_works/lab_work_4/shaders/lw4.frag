#version 450

layout(location = 0) out vec4 outputColor;

// Entrées depuis le vertex shader
in vec3 normalVector;
in vec3 viewVector;

// Uniformes pour les paramètres d'éclairage
uniform vec3 ambientLight;
uniform vec3 diffuseLight;
uniform vec3 specularLight;
uniform vec3 lightDir;
uniform float shininessFactor;

void main()
{
    // Normalisation des vecteurs
    vec3 normalizedNormal = normalize(normalVector);
    vec3 normalizedView = normalize(viewVector);
    vec3 normalizedLightDir = normalize(-lightDir);

    // Composante ambiante
    vec3 ambientComponent = ambientLight;

    // Composante diffuse (Lambert)
    float lambertTerm = max(dot(normalizedNormal, normalizedLightDir), 0.0);
    vec3 diffuseComponent = diffuseLight * lambertTerm;

    // Composante spéculaire (Blinn-Phong)
    vec3 halfVector = normalize(normalizedView + normalizedLightDir);
    float specularTerm = 0.0;
    if (lambertTerm > 0.0) {
        specularTerm = pow(max(dot(normalizedNormal, halfVector), 0.0), shininessFactor);
    }
    vec3 specularComponent = specularLight * specularTerm;

    // Couleur finale
    vec3 finalColor = ambientComponent + diffuseComponent + specularComponent;
    outputColor = vec4(finalColor, 1.0);
}
