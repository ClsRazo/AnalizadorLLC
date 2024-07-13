#include <stdio.h>

void llc(unsigned char trama[]);
void selector(unsigned char *);
void IP(unsigned char []);
void ARP(unsigned char []);
void ICMP(unsigned char []);
void UDP(unsigned char []);
void TCP(unsigned char []);
void armarPseudo(unsigned char [], unsigned char *);
void CS(unsigned char [], unsigned char );
void generarCompleta(unsigned char [], unsigned char *);
void mostrarTramaGen(unsigned char [], unsigned char);
void imprimeCaracteres(unsigned char []);

int main(){
    // unsigned char t[][200] =
	// 		        {
	// 				{0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x03, 0xf0, 0xf0,
	// 				 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x43, 0x05, 0x90, 0x6d}, //trama1
	// 				{0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x03, 0xf0, 0xf1,
	// 				 0x73, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x54, 0x90, 0x6d}, //trama2
	// 				{0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x04, 0xf0, 0xf0,
	// 				 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0xa3, 0x90, 0x6d}, //trama3
	// 				{0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x04, 0xf0, 0xf1,
	// 				 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf2, 0x90, 0x6d}, //trama4
	// 				{0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x12, 0xf0, 0xf0,
	// 				 0x00, 0x01, 0x0e, 0x00, 0xff, 0xef, 0x19, 0x8f, 0xbc, 0x05, 0x7f, 0x00, 0x23, 0x00, 0x7f, 0x23,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x91, 0x6d}, //trama5
	// 				{0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x12, 0xf0, 0xf0,
	// 				 0x00, 0x03, 0x0e, 0x00, 0xff, 0xef, 0x17, 0x81, 0xbc, 0x05, 0x23, 0x00, 0x7f, 0x00, 0x23, 0x7f,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x91, 0x6d}, //trama6
	// 				{0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x04, 0xf0, 0xf1,
	// 				 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xdf, 0x91, 0x6d}, //trama7
	// 				{0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x04, 0xf0, 0xf1,
	// 				 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xac, 0x92, 0x6d}, //trama8
	// 				{0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0xac, 0xf0, 0xf0,
	// 				 0x02, 0x02, 0x0e, 0x00, 0xff, 0xef, 0x16, 0x04, 0x00, 0x00, 0x00, 0x00, 0x28, 0x00, 0x7f, 0x23,
	// 				 0xff, 0x53, 0x4d, 0x42, 0x72, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x82, 0x09,
	// 				 0x00, 0x77, 0x00, 0x02, 0x50, 0x43, 0x20, 0x4e, 0x45, 0x54, 0x57, 0x4f, 0x52, 0x4b, 0x20, 0x50,
	// 				 0x52, 0x4f, 0x47, 0x52, 0x41, 0x4d, 0x20, 0x31, 0x2e, 0x30, 0x00, 0x02, 0x4d, 0x49, 0x43, 0x52,
	// 				 0x4f, 0x53, 0x4f, 0x46, 0x54, 0x20, 0x4e, 0x45, 0x54, 0x57, 0x4f, 0x52, 0x4b, 0x53, 0x20, 0x33,
	// 				 0x2e, 0x30, 0x00, 0x02, 0x44, 0x4f, 0x53, 0x20, 0x4c, 0x4d, 0x31, 0x2e, 0x32, 0x58, 0x30, 0x30,
	// 				 0x32, 0x00, 0x02, 0x44, 0x4f, 0x53, 0x20, 0x4c, 0x41, 0x4e, 0x4d, 0x41, 0x4e, 0x32, 0x2e, 0x31,
	// 				 0x00, 0x02, 0x57, 0x69, 0x6e, 0x64, 0x6f, 0x77, 0x73, 0x20, 0x66, 0x6f, 0x72, 0x20, 0x57, 0x6f,
	// 				 0x72, 0x6b, 0x67, 0x72, 0x6f, 0x75, 0x70, 0x73, 0x20, 0x33, 0x2e, 0x31, 0x61, 0x00, 0x02, 0x4e,
	// 				 0x54, 0x20, 0x4c, 0x4d, 0x20, 0x30, 0x2e, 0x31, 0x32, 0x00, 0x00, 0xfb, 0x92, 0x6d, 0x86, 0xdf}, //trama9
	// 				{0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x04, 0xf0, 0xf1,
	// 				 0x01, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7b, 0x93, 0x6d}, //trama10
	// 				{0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x5f, 0xf0, 0xf0,
	// 				 0x02, 0x04, 0x0e, 0x00, 0xff, 0xef, 0x16, 0x0c, 0x00, 0x00, 0x28, 0x00, 0x28, 0x00, 0x23, 0x7f,
	// 				 0xff, 0x53, 0x4d, 0x42, 0x72, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x82, 0x09,
	// 				 0x11, 0x05, 0x00, 0x02, 0x02, 0x00, 0x01, 0x00, 0x68, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,
	// 				 0x7f, 0x07, 0x00, 0x80, 0x03, 0x02, 0x00, 0x00, 0x00, 0xe5, 0xfe, 0x29, 0x25, 0x7c, 0xc2, 0x01,
	// 				 0x2c, 0x01, 0x08, 0x08, 0x00, 0x7f, 0x07, 0x00, 0x80, 0x32, 0x3e, 0xb9, 0x3d, 0x00, 0xca, 0x93}, //trama11
	// 				{0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x04, 0xf0, 0xf1,
	// 				 0x01, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x94, 0x6d}, //trama12
	// 				{0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x91, 0xf0, 0xf0,
	// 				 0x04, 0x04, 0x0e, 0x00, 0xff, 0xef, 0x16, 0x0c, 0x00, 0x00, 0x28, 0x00, 0x28, 0x00, 0x7f, 0x23,
	// 				 0xff, 0x53, 0x4d, 0x42, 0x73, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x82, 0x09,
	// 				 0x0d, 0x75, 0x00, 0x5d, 0x00, 0x68, 0x0b, 0x02, 0x00, 0x00, 0x00, 0x7f, 0x07, 0x00, 0x80, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x45,
	// 				 0x53, 0x43, 0x4f, 0x4d, 0x00, 0x57, 0x69, 0x6e, 0x64, 0x6f, 0x77, 0x73, 0x20, 0x34, 0x2e, 0x30,
	// 				 0x00, 0x57, 0x69, 0x6e, 0x64, 0x6f, 0x77, 0x73, 0x20, 0x34, 0x2e, 0x30, 0x00, 0x04, 0xff, 0x00,
	// 				 0x00, 0x00, 0x02, 0x00, 0x02, 0x00, 0x17, 0x00, 0x20, 0x00, 0x5c, 0x5c, 0x50, 0x52, 0x4f, 0x47,
	// 				 0x59, 0x44, 0x45, 0x53, 0x41, 0x5c, 0x49, 0x50, 0x43, 0x24, 0x00, 0x49, 0x50, 0x43, 0x00, 0x00}, //trama13
	// 				{0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x04, 0xf0, 0xf1,
	// 				 0x01, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x32, 0x95, 0x6d}, //trama14
	// 				{0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x46, 0xf0, 0xf0,
	// 				 0x04, 0x06, 0x0e, 0x00, 0xff, 0xef, 0x16, 0x0c, 0x00, 0x00, 0x28, 0x00, 0x28, 0x00, 0x23, 0x7f,
	// 				 0xff, 0x53, 0x4d, 0x42, 0x73, 0x00, 0x00, 0x00, 0x00, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x82, 0x09,
	// 				 0x03, 0x75, 0x00, 0x29, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0x00, 0x00, 0x00, 0x04, 0x00,
	// 				 0x49, 0x50, 0x43, 0x00, 0x00, 0x81, 0x95, 0x6d, 0x86, 0xcb, 0x94, 0x6d, 0x86, 0x0d, 0x09, 0x0e}, //trama15
	// 				{0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x04, 0xf0, 0xf1,
	// 				 0x01, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x96, 0x6d}, //trama16
	// 				{0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x7e, 0xf0, 0xf0,
	// 				 0x06, 0x06, 0x0e, 0x00, 0xff, 0xef, 0x16, 0x0c, 0x00, 0x00, 0x28, 0x00, 0x28, 0x00, 0x7f, 0x23,
	// 				 0xff, 0x53, 0x4d, 0x42, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x82, 0x0a,
	// 				 0x0e, 0x20, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x88, 0x13, 0x00,
	// 				 0x00, 0x00, 0x00, 0x20, 0x00, 0x4c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2d, 0x00, 0x5c,
	// 				 0x50, 0x49, 0x50, 0x45, 0x5c, 0x4c, 0x41, 0x4e, 0x4d, 0x41, 0x4e, 0x00, 0x68, 0x00, 0x57, 0x72,
	// 				 0x4c, 0x65, 0x68, 0x44, 0x7a, 0x00, 0x42, 0x31, 0x36, 0x42, 0x42, 0x44, 0x7a, 0x00, 0x01, 0x00,
	// 				 0x00, 0x10, 0xff, 0xff, 0xff, 0xff, 0x45, 0x53, 0x43, 0x4f, 0x4d, 0x00, 0x00, 0x6f, 0x96, 0x6d}, //trama17
	// 				{0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x04, 0xf0, 0xf1,
	// 				 0x01, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x96, 0x6d}, //trama18
	// 				{0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x04, 0xf0, 0xf1,
	// 				 0x01, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5d, 0x97, 0x6d}, //trama19
	// 				{0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x7e, 0xf0, 0xf0,
	// 				 0x08, 0x08, 0x0e, 0x00, 0xff, 0xef, 0x16, 0x0c, 0x00, 0x00, 0x28, 0x00, 0x28, 0x00, 0x7f, 0x23,
	// 				 0xff, 0x53, 0x4d, 0x42, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0b,
	// 				 0x0e, 0x20, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x88, 0x13, 0x00,
	// 				 0x00, 0x00, 0x00, 0x20, 0x00, 0x4c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2d, 0x00, 0x5c,
	// 				 0x50, 0x49, 0x50, 0x45, 0x5c, 0x4c, 0x41, 0x4e, 0x4d, 0x41, 0x4e, 0x00, 0x68, 0x00, 0x57, 0x72,
	// 				 0x4c, 0x65, 0x68, 0x44, 0x7a, 0x00, 0x42, 0x31, 0x36, 0x42, 0x42, 0x44, 0x7a, 0x00, 0x01, 0x00,
	// 				 0x00, 0x10, 0x00, 0x00, 0x00, 0x80, 0x45, 0x53, 0x43, 0x4f, 0x4d, 0x00, 0x00, 0xac, 0x97, 0x6d}, //trama20
	// 				{0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x04, 0xf0, 0xf1,
	// 				 0x01, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfb, 0x97, 0x6d}, //trama21
	// 				{0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x04, 0xf0, 0xf1,
	// 				 0x01, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x98, 0x6d}, //trama22
	// 				{0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x12, 0xf0, 0xf0,
	// 				 0x0a, 0x0b, 0x0e, 0x00, 0xff, 0xef, 0x14, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x7f, 0x23,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x99, 0x98, 0x6d}, //trama23
	// 				{0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x04, 0xf0, 0xf1,
	// 				 0x01, 0x0d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x45, 0x99, 0x6d}, //trama24
	// 				{0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x04, 0xac, 0x44, 0x4d, 0x02, 0x00, 0x8b, 0xf0, 0xf0,
	// 				 0x03, 0x2c, 0x00, 0xff, 0xef, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x34, 0x20,
	// 				 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x1b, 0x49, 0x42, 0x4d,
	// 				 0x53, 0x45, 0x52, 0x56, 0x45, 0x52, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0xff, 0x53, 0x4d,
	// 				 0x42, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00,
	// 				 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe8, 0x03, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x56, 0x00, 0x03, 0x00, 0x01, 0x00, 0x01, 0x00, 0x02, 0x00,
	// 				 0x17, 0x00, 0x5c, 0x4d, 0x41, 0x49, 0x4c, 0x53, 0x4c, 0x4f, 0x54, 0x5c, 0x42, 0x52, 0x4f, 0x57,
	// 				 0x53, 0x45, 0x00, 0x09, 0x04, 0x33, 0x17, 0x00, 0x00, 0x00, 0x9b, 0x99, 0x6d, 0x86, 0x99, 0x98}, //trama25
	// 				{0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x35, 0xf0, 0xf0,
	// 				 0x0c, 0x0a, 0x0e, 0x00, 0xff, 0xef, 0x16, 0x04, 0x00, 0x00, 0x00, 0x00, 0x28, 0x00, 0x7f, 0x23,
	// 				 0xff, 0x53, 0x4d, 0x42, 0x71, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x01, 0x50,
	// 				 0x00, 0x00, 0x00, 0x45, 0xf1, 0x99, 0x6d, 0x86, 0x45, 0x99, 0x6d, 0x86, 0x1f, 0x09, 0x52, 0x5b}, //trama26
	// 				{0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x35, 0xf0, 0xf0,
	// 				 0x0a, 0x0e, 0x0e, 0x00, 0xff, 0xef, 0x16, 0x0c, 0x00, 0x00, 0x28, 0x00, 0x28, 0x00, 0x23, 0x7f,
	// 				 0xff, 0x53, 0x4d, 0x42, 0x71, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x01, 0x50,
	// 				 0x00, 0x00, 0x00, 0x00, 0x40, 0x9a, 0x6d, 0x86, 0x9b, 0x99, 0x6d, 0x86, 0x20, 0x09, 0x75, 0x5b}, //trama27
	// 				{0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x12, 0xf0, 0xf0,
	// 				 0x0e, 0x0d, 0x0e, 0x00, 0xff, 0xef, 0x14, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x7f, 0x23,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8f, 0x9a, 0x6d}, //trama28
	// 				{0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x04, 0xf0, 0xf1,
	// 				 0x01, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xde, 0x9a, 0x6d}, //trama29
	// 				{0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x12, 0xf0, 0xf0,
	// 				 0x10, 0x0d, 0x0e, 0x00, 0xff, 0xef, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x23,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2d, 0x9b, 0x6d}, //trama30
	// 				{0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x04, 0xf0, 0xf1,
	// 				 0x01, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x9b, 0x6d}, //trama31
	// 				{0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x03, 0xf0, 0xf0,
	// 				 0x53, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xcb, 0x9b, 0x6d}, //trama32
	// 				{0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x03, 0xf0, 0xf1,
	// 				 0x73, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x77, 0x9c, 0x6d},//trama 33
	// 				{0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x08, 0x06, 0x00, 0x04, /*TRAMA a */
	// 				 0x08, 0x00, 0x06, 0x04, 0x00, 0x01, 0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x94, 0xcc, 0x39, 0xcb,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94, 0xcc, 0x39, 0xfe}, 
	// 				{0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x00, 0x1f, 0x45, 0x9d, 0x1e, 0xa2, 0x08, 0x16, 0x00, 0x01, /*TRAMA b */
	// 				 0x08, 0x00, 0x06, 0x04, 0x00, 0x02, 0x00, 0x1f, 0x45, 0x9d, 0x1e, 0xa2, 0x94, 0xcc, 0x39, 0xfe,
	// 				 0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x94, 0xcc, 0x39, 0xcb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// 				 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
	// 				{0x00, 0x1f, 0x45, 0x9d, 0x1e, 0xa2, 0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x08, 0x00, 0x46, 0x00, /* TRAMA c */
	// 				 0x80, 0x42, 0x04, 0x55, 0x34, 0x11, 0x80, 0x11, 0x6b, 0xf0, 0x94, 0xcc, 0x39, 0xcb, 0x94, 0xcc,
	// 				 0x67, 0x02, 0xaa, 0xbb, 0xcc, 0xdd, 0x04, 0x0c, 0x00, 0x35, 0x00, 0x2e, 0x85, 0x7c, 0xe2, 0x1a,
	// 				 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x77, 0x77, 0x77, 0x03, 0x69,
	// 				 0x73, 0x63, 0x05, 0x65, 0x73, 0x63, 0x6f, 0x6d, 0x03, 0x69, 0x70, 0x6e, 0x02, 0x6d, 0x78, 0x00,
	// 				 0x00, 0x1c, 0x00, 0x01}};
	// unsigned char t[][200] = {{0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x08, 0x06, 0x00, 0x04, //T1
	// 						0x08, 0x00, 0x06, 0x04, 0x00, 0x01, 0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x94, 0xcc, 0x39, 0xcb, 
	// 						0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94, 0xcc, 0x39, 0xfe                                      
	// 						},

	// 						{
	// 						0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x00, 0x1f, 0x45, 0x9d, 0x1e, 0xa2, 0x08, 0x06, 0x00, 0x01, //T2
	// 						0x08, 0x00, 0x06, 0x04, 0x00, 0x02, 0x00, 0x1f, 0x45, 0x9d, 0x1e, 0xa2, 0x94, 0xcc, 0x39, 0xfe, 
	// 						0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x94, 0xcc, 0x39, 0xcb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	// 						0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00                          
	// 						},
	// 						{
	// 						0x00, 0x1f, 0x45, 0x9d, 0x1e, 0xa2, 0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x08, 0x00, 0x46, 0x00, //T3
	// 						0x80, 0x42, 0x04, 0x55, 0x34, 0x11, 0x80, 0x11, 0x6b, 0xf0, 0x94, 0xcc, 0x39, 0xcb, 0x94, 0xcc, 
	// 						0x67, 0x02, 0xaa, 0xbb, 0xcc, 0xdd, 0x04, 0x0c, 0x00, 0x35, 0x00, 0x2e, 0x85, 0x7c, 0xe2, 0x1a, 
	// 						0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x77, 0x77, 0x77, 0x03, 0x69, 
	// 						0x73, 0x63, 0x05, 0x65, 0x73, 0x63, 0x6f, 0x6d, 0x03, 0x69, 0x70, 0x6e, 0x02, 0x6d, 0x78, 0x00, 
	// 						0x00, 0x1c, 0x00, 0x01                          
	// 						},
	// 						{
	// 						0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x04, 0xf0, 0xf1, //T4
	// 						0x09, 0x8d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	// 						0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	// 						0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x9b, 0x6d  
	// 						},
	// 						{
	// 						0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x08, 0x06, 0x00, 0x10, //T5
	// 						0x08, 0x00, 0x06, 0x04, 0x00, 0x03, 0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x94, 0xcc, 0x39, 0xcb, 
	// 						0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94, 0xcc, 0x3a, 0xe1                                      
	// 						},
	// 						{
	// 						0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x00, 0x1f, 0x45, 0x9d, 0x1e, 0xa2, 0x08, 0x06, 0x00, 0x10, //T6
	// 						0x08, 0x00, 0x06, 0x04, 0x00, 0x04, 0x00, 0x1f, 0x45, 0x9d, 0x1e, 0xa2, 0x94, 0xcc, 0x3a, 0xe1, 
	// 						0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x94, 0xcc, 0x39, 0xcb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	// 						0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00                          
	// 						},
	// 						{
	// 						0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x00, 0x1f, 0x45, 0x9d, 0x1e, 0xa2, 0x08, 0x00, 0x45, 0x00, //T7
	// 						0x00, 0x6f, 0x90, 0x30, 0x40, 0x00, 0xfb, 0x11, 0x24, 0xe7, 0x94, 0xcc, 0x67, 0x02, 0x94, 0xcc, 
	// 						0x39, 0xcb, 0x00, 0x35, 0x04, 0x0c, 0x00, 0x5b, 0xe8, 0x60, 0xe2, 0x1a, 0x85, 0x80, 0x00, 0x01, 
	// 						0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x03, 0x77, 0x77, 0x77, 0x03, 0x69, 0x73, 0x63, 0x05, 0x65, 
	// 						0x73, 0x63, 0x6f, 0x6d, 0x03, 0x69, 0x70, 0x6e, 0x02, 0x6d, 0x78, 0x00, 0x00, 0x1c, 0x00, 0x01, 
	// 						0xc0, 0x14, 0x00, 0x06, 0x00, 0x01, 0x00, 0x00, 0x0e, 0x10, 0x00, 0x21, 0x04, 0x64, 0x6e, 0x73, 
	// 						0x31, 0xc0, 0x1a, 0x03, 0x74, 0x69, 0x63, 0xc0, 0x1a, 0x77, 0xec, 0xdf, 0x29, 0x00, 0x00, 0x2a, 
	// 						0x30, 0x00, 0x00, 0x0e, 0x10, 0x00, 0x12, 0x75, 0x00, 0x00, 0x00, 0x2a, 0x30                    
	// 						},

	// 						{
	// 						0x00, 0x1f, 0x45, 0x9d, 0x1e, 0xa2, 0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x08, 0x00, 0x45, 0x00, //T8
	// 						0x00, 0x3c, 0x04, 0x57, 0x00, 0x00, 0x80, 0x01, 0x98, 0x25, 0x94, 0xcc, 0x39, 0xcb, 0x94, 0xcc, 
	// 						0x3a, 0xe1, 0x08, 0x00, 0x49, 0x5c, 0x03, 0x00, 0x01, 0x00, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 
	// 						0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 
	// 						0x77, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69                                      
	// 						},
	// 						{
	// 						0x00, 0x1f, 0x45, 0x9d, 0x1e, 0xa2, 0x00, 0x1c, 0xc0, 0x7b, 0x35, 0xa1, 0x08, 0x00, 0x48, 0x00, //T9
	// 						0x00, 0x48, 0x5c, 0x7d, 0x00, 0x00, 0x80, 0x01, 0x6c, 0x88, 0x94, 0xcc, 0x39, 0xc3, 0x94, 0xcc, 
	// 						0x00, 0x49, 0x07, 0x0b, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 
	// 						0x3b, 0x5c, 0x02, 0x00, 0x10, 0x00, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 
	// 						0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x61, 0x62, 0x63, 
	// 						0x64, 0x65, 0x66, 0x67, 0x68, 0x69              
	// 						},
	// 						{
	// 						0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x00, 0x1f, 0x45, 0x9d, 0x1e, 0xa2, 0x80, 0x35, 0x00, 0x01, //T10
	// 						0x08, 0x00, 0x06, 0x04, 0x00, 0x03, 0x00, 0x1f, 0x45, 0x9d, 0x1e, 0xa2, 0x94, 0xcc, 0x3a, 0xe1, 
	// 						0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x94, 0xcc, 0x39, 0xcb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	// 						0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd8, 0xee, 0xdf, 0xb0  
	// 						},
	// 						{
	// 						0x02, 0xff, 0x53, 0xc3, 0xe9, 0xab, 0x00, 0xff, 0x66, 0x7f, 0xd4, 0x3c, 0x08, 0x00, 0x45, 0x00, //T11
	// 						0x00, 0x30, 0x2c, 0x00, 0x40, 0x00, 0x80, 0x06, 0x4b, 0x74, 0xc0, 0xa8, 0x01, 0x02, 0xc0, 0xa8, 
	// 						0x01, 0x01, 0x04, 0x03, 0x00, 0x15, 0x00, 0x3b, 0xcf, 0x44, 0x00, 0x00, 0x00, 0x00, 0x70, 0x20, 
	// 						0x20, 0x00, 0x0c, 0x34, 0x00, 0x00, 0x02, 0x04, 0x05, 0xb4, 0x01, 0x01, 0x04, 0x02              
	// 						},
	// 						{
	// 						0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x12, 0xf0, 0xf0, //T12
	// 						0x0a, 0x0b, 0x0e, 0x00, 0xff, 0xef, 0x14, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x7f, 0x23, 
	// 						0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	// 						0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x99, 0x98, 0x6d  
	// 						}};
	// unsigned char t[][200] = {{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xE0, 0xA3, 0xEC, 0x50, 0x93, 0x08, 0x06, 0x00, 0x01,
	// 						 0x08, 0x00, 0x06, 0x04, 0x00, 0x01, 0x00, 0xE0, 0xA3, 0xEC, 0x50, 0x93, 0xC8, 0x01, 0x01, 0x81,
	// 						 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC8, 0x01, 0x01, 0x82},
	// 						 {0x00, 0xE0, 0xA3, 0xEC, 0x50, 0x93, 0x00, 0x00, 0x0C, 0xC0, 0x6E, 0x56, 0x08, 0x06, 0x00, 0x01,
	// 						 0x08, 0x00, 0x06, 0x04, 0x00, 0x02, 0x00, 0x00, 0x0C, 0xC0, 0x6E, 0x56, 0xC8, 0x01, 0x01, 0x82,
	// 						 0x00, 0xE0, 0xA3, 0xEC, 0x50, 0x93, 0xC8, 0x01, 0x01, 0x81},
	// 						 {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xE0, 0xA3, 0xEC, 0x50, 0x93, 0x08, 0x06, 0x00, 0x01,
	// 						 0x08, 0x00, 0x06, 0x04, 0x00, 0x01, 0x00, 0xE0, 0xA3, 0xEC, 0x50, 0x93, 0xC8, 0x01, 0x01, 0x81,
	// 						 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC8, 0x01, 0x01, 0x04},
	// 						 {0x00, 0xE0, 0xA3, 0xEC, 0x50, 0x93, 0x00, 0x60, 0x3E, 0x37, 0x41, 0x01, 0x08, 0x06, 0x00, 0x01,
	// 						 0x08, 0x00, 0x06, 0x04, 0x00, 0x02, 0x00, 0x60, 0x3E, 0x37, 0x41, 0x01, 0xC8, 0x01, 0x01, 0xBE,
	// 						 0x00, 0xE0, 0xA3, 0xEC, 0x50, 0x93, 0xC8, 0x01, 0x01, 0x81},
	// 						{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x60, 0x3E, 0x37, 0x41, 0x02, 0x08, 0x06, 0x00, 0x01,
	// 						 0x08, 0x00, 0x06, 0x04, 0x00, 0x01, 0x00, 0x60, 0x3E, 0x37, 0x41, 0x02, 0xC8, 0x01, 0x01, 0x3E,
	// 						 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC8, 0x01, 0x01, 0x04},
	// 						 {0x00, 0x60, 0x3E, 0x37, 0x41, 0x02, 0x00, 0x06, 0x2A, 0xCC, 0x60, 0x47, 0x08, 0x06, 0x00, 0x01,
	// 						 0x08, 0x00, 0x06, 0x04, 0x00, 0x02, 0x00, 0x06, 0x2A, 0xCC, 0x60, 0x47, 0xC8, 0x01, 0x01, 0x04,
	// 						 0x00, 0x60, 0x3E, 0x37, 0x41, 0x02, 0xC8, 0x01, 0x01, 0x3E}};

	unsigned char t[][200] = {{0x00, 0x14, 0xd1, 0xc2, 0x38, 0xbe, 0x00, 0x18, 0xe7, 0x33, 0x3d, 0xc3, 0x08, 0x00, 0x45, 0x00,
								0x00, 0x30, 0x94, 0x71, 0x40, 0x00, 0x80, 0x06, 0xf9, 0x8c, 0xc0, 0xa8, 0x02, 0x3c, 0x4a, 0x7d
								, 0x5f, 0x68, 0x10, 0x52, 0x00, 0x50, 0x03, 0xc7, 0x5a, 0xa1, 0x00, 0x00, 0x00, 0x00, 0x70
								, 0x02, 0x40, 0x00, 0x67, 0x4b, 0x00, 0x00, 0x02, 0x04, 0x05, 0xb4, 0x01, 0x01, 0x04, 0x02},
								{0x00, 0x01, 0xf4, 0x43, 0xc9, 0x19, 0x00, 0x50, 0xba, 0xb2, 0xf3, 0x7b, 0x08, 0x00, 0x45,
								0x00, 0x00, 0x3c, 0x09, 0x0d, 0x00, 0x00, 0x80, 0x01, 0x7b, 0xfe, 0x94, 0xcc, 0x19, 0x1b,
								0x94, 0xcc, 0x73, 0x02, 0x08, 0x00, 0x58, 0x5a, 0x02, 0x00, 0xf3, 0x01, 0x61, 0x62, 0x63, 0x64,
								0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6a, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74,
								0x75, 0x76, 0x77, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69},
								{0x00, 0x50, 0xba, 0xb2, 0xf3, 0x7b, 0x00, 0x01, 0xf4, 0x43, 0xc9, 0x19, 0x08, 0x00, 0x45, 0x00,
								0x00, 0x3c, 0xdf, 0x5c, 0x00, 0x00, 0x7c, 0x01, 0xa9, 0xae, 0x94, 0xcc, 0x73, 0x02, 0x94, 0xcc,
								0x19, 0x1b, 0x00, 0x00, 0x60, 0x5a, 0x02, 0x00, 0xf3, 0x01, 0x61, 0x62, 0x63, 0x64,
								0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6a, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74,
								0x75, 0x76, 0x77, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69},
								{0x00, 0x02, 0xd1, 0x02, 0xd4, 0xca, 0x00, 0x50, 0xda, 0xb2, 0xf3, 0x7b, 0x08, 0x00, 0x45, 0x00,
								0x00, 0x3f, 0x07, 0xdc, 0x00, 0x00, 0x80, 0x11, 0xd6, 0xaf, 0x94, 0xcc, 0x19, 0x1b, 0x94, 0xcc,
								0x19, 0x6f, 0x04, 0x0c, 0x00, 0x35, 0x00, 0x2b, 0x4e, 0x6d, 0x52, 0xa7, 0x01, 0x00, 0x00, 0x01, 
								0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x77, 0x77, 0x77, 0x06, 0x67, 0x6f, 0x6f, 0x67, 0x6e,
								0x65, 0x03, 0x63, 0x6f, 0x6d, 0x02, 0x6d, 0x78, 0x00, 0x00, 0x01, 0x00, 0x01},
								{
								0x00, 0x02, 0xd1, 0x02, 0xd4, 0xca, 0x00, 0x50, 0xba, 0xb2, 0xf3, 0x7b, 0x08, 0x00, 0x45, 0x00, //UDP
								0x00, 0x3f, 0x07, 0xdc, 0x00, 0x00, 0x80, 0x11, 0xd6, 0xaf, 0x94, 0xcc, 0x19, 0x1b, 0x94, 0xcc,
								0x9, 0x6f, 0x04, 0x0c, 0x00, 0x35, 0x00, 0x2b, 0x4e, 0x6d, 0x52, 0xa7, 0x01, 0x00, 0x00, 0x01,
								0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x77, 0x77, 0x77, 0x06, 0x67, 0x6f, 0x6f, 0x6f, 0x67
								}
};

    unsigned char i;

	printf("\n\t\t\t\tPEREZ BARCENAS JUAN RUBEN\n\t\t\t\tVILLARREAL RAZO CARLOS GABRIEL\n");

    for(i = 0; i < 5; i++){
        printf("\n\t\t\t------------------------TRAMA %d------------------------\n",i+1);
        selector(t[i]);
    }
	printf("\n");
    return 0;
}

void selector(unsigned char *t){
    unsigned short int tot=((t[12]<<8)|t[13]);
    printf("\n\t\t\t**Cabecera Ethernet**\n");
    printf("\nMAC Destino: %.2X:%.2X:%.2X:%.2X:%.2X:%.2X", t[0], t[1], t[2], t[3], t[4], t[5]);
    printf("\nMAC Origen: %.2X:%.2X:%.2X:%.2X:%.2X:%.2X", t[6], t[7], t[8], t[9], t[10], t[11]);
    if(tot <= 1500){
        printf("\nEl tama%co de la cabecera LLC es de: %d bytes\n", 164, tot);
        printf("\n\n\t\t\t**** Cabecera LLC ****\n");
        llc(t);
    }else{
        if(tot == 2048){
            printf("\nTipo: IP", 164, tot);
            IP(t);
        }else if(tot == 2054){
            printf("\nTipo: ARP", 164, tot);
            ARP(t);
        }else{
            printf("\nTipo: OTRO", 164, tot);
            printf("\n\n\t\t\t**** OTRO ****\nTama%co: 0x%.4X\n",164,tot);
        }
    }
}

void llc(unsigned char trama[]){
    char ur[][5] = {"UI","RIM","-","DM","-","-","-","-","RD","-","-","-","UA","-","-","-","-","FMRM","-","-","-","-","-","XID","-","-","-","-"};
    char uc[][6] = {"UI","SIM","-","SARM","UP","-","-","SABM","DISC","-","-","SARME","-","-","-","SABME","SNRM","-","-","RSET","-","-","-","XID","-","-","-","SNRME"};
    char ss[][5] = {"RR","RNR","REJ","SREJ"};

    switch(trama[16]&3){
        case 1:
            printf("\nTrama de Supervision: S = %s, N(R) = %d",ss[((trama[16] >> 2) & 3)],trama[17] >> 1);
            if(trama[17] & 1){
                //printf("\np/f = 1\n");
                if(trama[15] & 1){
                    //printf("\nSAPo = 1\n");
                    printf(", f\n");
                }else{
                    //printf("\nSAPo = 0\n");
                    printf(", p\n");
                }
            }
            break;
        case 3:
            printf("\nTrama No Numerada: ");
            if(trama[16] & 16){
                if(trama[15] & 1){
                    printf("U = %s, f\n",ur[((trama[16] >> 2) & 3) | ((trama[16] >> 3) & 28)]);
                }else{
                    printf("U = %s, p\n",uc[((trama[16] >> 2) & 3) | ((trama[16] >> 3) & 28)]);
                }
            }
            break;
        default:
            printf("\nTrama de Informacion: I, N(S) = %d, N(R) = %d",trama[16] >> 1,trama[17] >> 1);
            if(trama[17] & 1){
                if(trama[15] & 1){
                    printf(", f\n");
                }else{
                    printf(", p\n");
                }
            }
            break;
    }
}

void IP(unsigned char t[]){
    printf("\n\n\t\t\t**** Cabecera IP ****\n");
	printf("\nVersion: %d",t[14] >> 4);
	printf("\nIHL: %d", t[14] & 15);
	printf("\nTama%co de la cabecera IP: %d bytes", 164, (t[14] & 15) << 2);
	
	if(t[15] & 16)
		printf("\nTipo de Servicio: Retardo minimo\n");
	if(t[15] & 8)
		printf("\nTipo de Servicio: Maximizar todo\n");
	if(t[15] & 4)
		printf("\nTipo de Servicio: Maximizar fiabilidad\n");
	if(t[15] & 2)
		printf("\nTipo de Servicio: Costo minimo\n");

	printf("\nTotal Length: %d bytes", (t[16] << 8) | t[17]);
	printf("\nID: %d\n", (t[18] << 8) | t[19]);

	if(t[20] & 64)
		printf("\nNo hay mas fragmentos\n");
	if(t[20] & 32)
		printf("\nHay mas fragmentos\n");

	printf("\nFragment Offset: %d bytes", ((t[20] & 31 << 8) | t[21]) << 3);
	printf("\nTiempo de vida: %d saltos",t[22]);

	printf("\nProtocolo: ");
	switch (t[23]){
	case 1:
		printf("ICMP\n");
		break;
	case 6:
		printf("TCP\n");
		break;
	case 17:
		printf("UDP\n");
		break;
	}

	printf("\nChecksum: 0x%.2X\n",(t[24] << 8) | t[25]);
	printf("\nIP Origen: %d.%d.%d.%d",t[26], t[27], t[28], t[29]);
	printf("\nIP Destino: %d.%d.%d.%d\n\n",t[30], t[31], t[32], t[33]);

	switch (t[34]){
	case 0:
		printf("\nFinal de Lista Opcional\n");
		break;
	case 1:
		printf("\nSin Operacion\n");
		break;
	case 7:
		printf("\nRegistrar Ruta\n");
		break;
	case 68:
		printf("\nMarca de Tiempo\n");
		break;
	case 131:
		printf("\nRuta de Origen Perdida\n");
		break;
	case 137:
		printf("\nRuta de Origen Estricta\n");
		break;
	}

	switch (t[23]){
	case 1:
		ICMP(t);
		break;
	case 6:
		TCP(t);
		break;
	case 17:
		UDP(t);
		break;
	}

}

void ARP(unsigned char t[]){
    printf("\n\n\t\t\t**** Cabecera ARP ****\n");

	switch ((t[14] << 8) | t[15]){
	case 1:
		printf("\nTipo de MAC: Ethernet\n");
		break;
	case 6:
		printf("\nTipo de MAC: IEEE 802 LAN\n");
		break;
	default:
		printf("\nTipo de MAC: OTRO\n");
		break;
	}

	switch ((t[16] << 8) | t[17]){
	case 2048:
		printf("\nTipo de IP: IPv4\n");
		break;
	default:
		printf("\nTipo de IP: OTRO\n");
		break;
	}

	printf("\nTama%co de la MAC: %d bytes",164, t[18]);
	printf("\nTama%co de la IP: %d bytes\n",164, t[19]);

	switch ((t[20] << 8) | t[21]){
	case 1:
		printf("\nOperacion: Solicitud\n");
		break;
	case 2:
		printf("\nOperacion: Respuesta\n");
		break;
	default:
		printf("\nOperacion: OTRO\n");
		break;
	}

	printf("\nMAC Origen: %.2X:%.2X:%.2X:%.2X:%.2X:%.2X", t[22], t[23], t[24], t[25], t[26], t[27]);
	printf("\nIP Origen: %d.%d.%d.%d\n", t[28], t[29], t[30], t[31]);

	printf("\nMAC Destino: %.2X:%.2X:%.2X:%.2X:%.2X:%.2X", t[32], t[33], t[34], t[35], t[36], t[37]);
	printf("\nIP Destino: %d.%d.%d.%d\n", t[38], t[39], t[40], t[41]);
}

void ICMP(unsigned char t[]){
	unsigned char IHL = (t[14] & 15) << 2;

	printf("\n\t\t\t**** Cabecera ICMP ****\n");
	printf("\nTipo: ");
	if(t[14+IHL] == 8 && t[15+IHL] == 0){
		printf("Solicitud ECHO\n\n");
		printf("Checksum: 0x%.4X\n", t[16+IHL] << 8 | t[17+IHL]);
		printf("Identificador: %d\n", t[18+IHL] << 8 | t[19+IHL]);
		printf("No. de Secuencia: %d\n", t[20+IHL] << 8 | t[21+IHL]);
		printf("Datos Opcionales: ");
		imprimeCaracteres(t);
		printf("\n");
	}else if(t[14+IHL] == 0 && t[15+IHL] == 0){
		printf("Respuesta ECHO\n\n");
		printf("Checksum: 0x%.4X\n", t[16+IHL] << 8 | t[17+IHL]);
		printf("Identificador: %d\n", t[18+IHL] << 8 | t[19+IHL]);
		printf("No. de Secuencia: %d\n", t[20+IHL] << 8 | t[21+IHL]);
		printf("Datos Opcionales: ");
		imprimeCaracteres(t);
		printf("\n");
	}else if(t[14+IHL] == 3 && (t[15+IHL] >= 0 && t[15+IHL] <= 13)){
		printf("Destino Inalcanzable\n");
	}else{
		printf("OTRO\n");
	}
}

void imprimeCaracteres(unsigned char t[]){
	unsigned char IHL = (t[14] & 15) << 2, i;
	for(i = 22; i < IHL + 22 + 32; i++){
		printf("%c", t[i+IHL]);
	}
}

void UDP(unsigned char t[]){
	unsigned char IHL = (t[14] & 15) << 2;

	printf("\n\t\t\t**** Cabecera UDP ****\n\n");
	printf("Puerto Origen: 0x%.4X\n", t[14+IHL] << 8 | t[15+IHL]);
	printf("Puerto Destino: 0x%.4X\n", t[16+IHL] << 8 | t[17+IHL]);
	printf("Tama%co: %d bytes\n", 164, t[18+IHL] << 8 | t[19+IHL]);
	printf("Checksum: 0x%.4X\n", t[20+IHL] << 8 | t[21+IHL]);
}

void TCP(unsigned char t[]){
	printf("\n\t\t\t**** Cabecera TCP ****\n");
	//PseudoCabecera
	unsigned char pt[12];
	//Armar pseudocabecera TCP
	armarPseudo(t,pt);
	//Armar pseudocabecera + cabecera TCP
	generarCompleta(t, pt);
}

void armarPseudo(unsigned char t[], unsigned char *pt){
	//IP origen
	pt[0] = t[26];
	pt[1] = t[27];
	pt[2] = t[28];
	pt[3] = t[29];
	//IP destino
	pt[4] = t[30];
	pt[5] = t[31];
	pt[6] = t[32];
	pt[7] = t[33];
	//No usado
	pt[8] = 0;
	//Protocolo
	pt[9] = 0x06;
	//IHL para offset
	unsigned char IHL = (t[14] & 15) << 2;
	pt[10] = 0;
	pt[11] = (t[IHL+26] >> 4) << 2;
}

void generarCompleta(unsigned char t[], unsigned char *pt){
	unsigned char IHL = (t[14] & 15) << 2, THL = (t[IHL+26] >> 4) << 2;
	unsigned char newT[12+THL];
	unsigned char i, j, k;

	for(i = IHL + 14, j = 0, k = 0; k < 12 + THL; k++){
		if(j < 12) {
			newT[k] = pt[j];
			j++;
		}else if (i < (IHL + 14 + THL)){
			newT[k] = t[i];
			i++;
		}
	}

	mostrarTramaGen(newT, 12+THL);
	printf("Checksum TCP: 0x%.4X\n\nVerificacion Checksum: ", t[30+IHL] << 8 | t[31+IHL]);
	CS(newT, 12+THL);
}

void CS(unsigned char t[], unsigned char tam){
    unsigned char i/*, comp*/;
    unsigned int duplas = 0;
    unsigned short checksum;

    for (i = 0; i < tam; i += 2){
        duplas += ((t[i] << 8 | t[i + 1]));
    }

	//Checksum
    checksum = ~((duplas & 0xFFFF) + (duplas >> 16));
    //printf("\nChecksum = 0x%.4X\n\n", checksum);

    //Comprobación Checksum
    // comp = ~((checksum) + ((duplas & 0xFFFF) + (duplas >> 16)));
    //printf("Comprobacion = 0x%.4X\n\n", comp);

	if(checksum == 0){
		printf("0x%.4X, Trama CORRECTA\n", checksum);
	}else{
		printf("0x%.4X, Trama INCORRECTA\n", checksum);
	}
}

void mostrarTramaGen(unsigned char t[], unsigned char tam){
	unsigned char i;

	printf("\nTrama generada de \033[1;34mPseudocabecera TCP\033[0m + \033[1;35mCabecera TCP\033[0m:\n");
	for(i = 0; i < tam; i++){
		if(i % 16 == 0){
			printf("\n");
		}
		if(i < 12){
			//Azul para la pseudocabecera
			printf("\033[1;34m%.2X \033[0m", t[i]);
		}else{
			//Morado para la pseudocabecera
			printf("\033[1;35m%.2X \033[0m", t[i]);
		}
	}
	printf("\n\n");
}
