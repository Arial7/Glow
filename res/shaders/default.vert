#version 130

in vec4 position;
in vec4 color;

uniform mat4 projection_matrix;
uniform mat4 modelview_matrix = mat4(1.0);

out vec4 vs_position;
out vec4 vs_color;


void main(void){
    gl_FrontColor = color;
    gl_Position = /*projection_matrix * */ position;
    vs_color = color;
    vs_position = position;
}
