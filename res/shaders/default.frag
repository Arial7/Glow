#version 130

in vec4 vs_position;
in vec4 vs_color;

void main(void){
    gl_FragColor = vs_color;
}
