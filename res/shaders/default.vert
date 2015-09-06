#version 130

vec4 position;
vec4 color;

uniform mat4 projection_matrix;
uniform mat4 modelview_matrix = mat(1.0);

out vec4 vs_position;
out vec4 vs_color;


void main(void){
    gl_Position = /*projection_matrix * */ position;
    vs_color = color;

}
