#version 130

in vec3 position;

out vec3 color;

void main(void){
    gl_FrontColor = gl_Color; 
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
    color = vec3(gl_Color.xyz);
}


