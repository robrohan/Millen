#glbuild(ES2) #version 100
#glbuild(2) #version 110
#glbuild(3) #version 140

#ifdef GL_ES
precision lowp float;
#define o_fragcolour gl_FragColor
#elif __VERSION__ < 140
#define mediump
#define o_fragcolour gl_FragColor
#else
#define varying in
#define texture2D texture
out vec4 o_fragcolour;
#endif

uniform sampler2D u_texture;
uniform sampler2D u_glowtexture;

uniform vec4 u_colour;
uniform float u_alphacut;
uniform vec4 u_fogcolour;
uniform float u_fogdensity;
uniform float u_time;

varying mediump vec2 v_texcoord;

vec4 applyfog(vec4 inputcolour) {
  const float LOG2_E = 1.442695;
  float dist = gl_FragCoord.z / gl_FragCoord.w;
  float densdist = u_fogdensity * dist;
  float amount = 1.0 - clamp(exp2(-densdist * densdist * LOG2_E), 0.0, 1.0);
  return mix(inputcolour, u_fogcolour, amount);
}

void main(void) {
  vec4 texcolour;
  vec4 glowcolour;

  texcolour = texture2D(u_texture, v_texcoord);
  glowcolour = texture2D(u_glowtexture, v_texcoord);

  if (texcolour.a < u_alphacut) {
    discard;
  }

  texcolour = applyfog(texcolour);
  o_fragcolour = mix(texcolour * u_colour, glowcolour, glowcolour.a);
}

//////////////////////////////////////////////////////////////////
// Noise for Water kind of things
// vec2 hash(vec2 p) {
//   p = vec2(dot(p, vec2(127.1, 311.7)), dot(p, vec2(269.5, 183.3)));
//   return -1.0 + 2.0 * fract(sin(p) * 43758.5453123);
// }

// float noise(in vec2 p) {
//   const float K1 = 0.366025404; // (sqrt(3)-1)/2;
//   const float K2 = 0.211324865; // (3-sqrt(3))/6;

//   vec2 i = floor(p + (p.x + p.y) * K1);
//   vec2 a = p - i + (i.x + i.y) * K2;
//   vec2 o = (a.x > a.y) ? vec2(1.0, 0.0) : vec2(0.0, 1.0);
//   vec2 b = a - o + K2;
//   vec2 c = a - 1.0 + 2.0 * K2;
//   vec3 h = max(0.5 - vec3(dot(a, a), dot(b, b), dot(c, c)), 0.0);
//   vec3 n =
//       h * h * h * h *
//       vec3(dot(a, hash(i + 0.0)), dot(b, hash(i + o)), dot(c, hash(i
//       + 1.0)));
//   return dot(n, vec3(70.0));
// }

// float n(vec2 p, float s) {
//   vec2 uv = p;
//   float tex = noise(vec2(uv.x, uv.y + s));
//   return tex;
// }
/////////////////////////////////////////////////////////
// vec2 uv = v_texcoord.xy;
// float npos = -u_time * .3;
// float tex = n(v_texcoord * 1.5, npos) * .05;
// vec2 p = uv + tex;
// o_fragcolour =
//    vec4(texture2D(u_texture, vec2(p.x, p.y - (u_time * .05))).rgba);
/////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
