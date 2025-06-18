xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 22;
 0.00000;0.00000;0.00612;,
 0.00000;0.00000;-8.37322;,
 9.53952;0.00000;0.00612;,
 0.00000;0.00000;8.38546;,
 -9.53952;0.00000;0.00612;,
 0.00000;17.13056;-4.51794;,
 0.00000;20.66399;0.00612;,
 5.14830;17.01530;0.00612;,
 9.53952;0.00000;0.00612;,
 0.00000;0.00000;-8.37322;,
 5.14830;17.01530;0.00612;,
 0.00000;20.66399;0.00612;,
 0.00000;16.89182;4.62700;,
 0.00000;0.00000;8.38546;,
 0.00000;16.89182;4.62700;,
 0.00000;20.66399;0.00612;,
 -5.14851;17.01488;0.00612;,
 -9.53952;0.00000;0.00612;,
 -5.14851;17.01488;0.00612;,
 0.00000;20.66399;0.00612;,
 0.00000;17.13056;-4.51794;,
 0.00000;0.00000;-8.37322;;
 
 12;
 3;0,1,2;,
 3;0,2,3;,
 3;0,3,4;,
 3;0,4,1;,
 3;5,6,7;,
 4;5,7,8,9;,
 3;10,11,12;,
 4;10,12,13,8;,
 3;14,15,16;,
 4;14,16,17,13;,
 3;18,19,20;,
 4;18,20,21,17;;
 
 MeshMaterialList {
  1;
  12;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\block000.jpg";
   }
  }
 }
 MeshNormals {
  11;
  0.000000;-1.000000;0.000000;,
  -0.000016;0.788108;-0.615537;,
  0.595532;0.446950;-0.667516;,
  0.592185;0.440849;0.674514;,
  -0.592196;0.440842;0.674509;,
  0.651791;0.167091;-0.739763;,
  -0.000016;0.774659;0.632379;,
  0.653673;0.165841;0.738382;,
  -0.653670;0.165840;0.738385;,
  -0.595543;0.446942;-0.667512;,
  -0.651787;0.167090;-0.739766;;
  12;
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;2,1,2;,
  4;2,2,5,5;,
  3;3,6,3;,
  4;3,3,7,7;,
  3;4,6,4;,
  4;4,4,8,8;,
  3;9,1,9;,
  4;9,9,10,10;;
 }
 MeshTextureCoords {
  22;
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.103630;0.170990;,
  0.125000;0.000000;,
  0.147070;0.176570;,
  0.250000;1.000000;,
  0.000000;1.000000;,
  0.250000;0.176570;,
  0.250000;0.000000;,
  0.295640;0.182550;,
  0.500000;1.000000;,
  0.397820;0.182550;,
  0.375000;0.000000;,
  0.441220;0.176590;,
  0.750000;1.000000;,
  0.544150;0.176590;,
  0.500000;0.000000;,
  0.585500;0.170990;,
  1.000000;1.000000;;
 }
}
