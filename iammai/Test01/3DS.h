#ifndef ___3DS_H___
#define ___3DS_H___

#include <math.h>
#include <vector>
#include<windef.h>
#include<gl/gl.h>
#include<gl/GLU.h>
//  ������(Primary Chunk)��λ���ļ��Ŀ�ʼ
#define PRIMARY       0x4D4D
//  ����(Main Chunks)
#define OBJECTINFO    0x3D3D		// �������İ汾��
#define VERSION       0x0002		// .3ds�ļ��İ汾
#define EDITKEYFRAME  0xB000		// ���йؼ�֡��Ϣ��ͷ��
//  ����Ĵμ�����(��������Ĳ��ʺͶ���
#define MATERIAL	  0xAFFF		// ����������Ϣ
#define OBJECT		  0x4000		// ���������桢�������Ϣ
//  ���ʵĴμ�����
#define MATNAME       0xA000		// �����������
#define MATDIFFUSE    0xA020		// ����/���ʵ���ɫ
#define MATMAP        0xA200		// �²��ʵ�ͷ��
#define MATMAPFILE    0xA300		// �����������ļ���
#define OBJ_MESH	  0x4100		// �µ��������
#define MAX_TEXTURES  100			// ����������Ŀ
//  OBJ_MESH�Ĵμ�����
#define OBJ_VERTICES  0x4110		// ���󶥵�
#define OBJ_FACES	  0x4120		// �������
#define OBJ_MATERIAL  0x4130		// ����Ĳ���
#define OBJ_UV		  0x4140		// �����UV��������

using namespace std;
class CVector3		//����3D����࣬���ڱ���ģ���еĶ���
{
public:	float x, y, z;
};
class CVector2		//����2D���࣬���ڱ���ģ�͵�UV��������
{
public:	float x, y;
};
struct tFace		//��Ľṹ����
{
	int vertIndex[3];			// ��������
	int coordIndex[3];			// ������������
};
struct tMatInfo//������Ϣ�ṹ��
{
	char  strName[255];			// ��������
	char  strFile[255];			// �����������ӳ�䣬���ʾ�����ļ�����
	BYTE  color[3];				// �����RGB��ɫ
	int   texureId;				// ����ID
	float uTile;				// u �ظ�
	float vTile;				// v �ظ�
	float uOffset;			    // u ����ƫ��
	float vOffset;				// v ����ƫ��
};
struct t3DObject	//������Ϣ�ṹ��
{
	int  numOfVerts;			// ģ���ж������Ŀ
	int  numOfFaces;			// ģ���������Ŀ
	int  numTexVertex;			// ģ���������������Ŀ
	int  materialID;			// ����ID
	bool bHasTexture;			// �Ƿ��������ӳ��
	char strName[255];			// ���������
	CVector3  *pVerts;			// ����Ķ���
	CVector3  *pNormals;		// ����ķ�����
	CVector2  *pTexVerts;		// ����UV����
	tFace *pFaces;				// ���������Ϣ
};
struct t3DModel	//ģ����Ϣ�ṹ��
{
	int numOfObjects;			// ģ���ж������Ŀ
	int numOfMaterials;			// ģ���в��ʵ���Ŀ
	vector<tMatInfo>pMaterials;	// ����������Ϣ
	vector<t3DObject> pObject;	// ģ���ж���������Ϣ
};
struct tChunk	//�������Ϣ�Ľṹ
{
	unsigned short int ID;		// ���ID		
	unsigned int length;		// ��ĳ���
	unsigned int bytesRead;		// ��Ҫ���Ŀ����ݵ��ֽ���
};
//////////////////////////////////////////////////////////////////////////
class CLoad3DS// CLoad3DS�ദ�����е�װ�����
{
public:
	CLoad3DS();								// ��ʼ�����ݳ�Ա
	virtual ~CLoad3DS();
	void show3ds(int j0, float tx, float ty, float tz, float size);//��ʾ3dsģ��
	void Init(char *filename, int j);
private:
	bool Import3DS(t3DModel *pModel, char *strFileName);// װ��3ds�ļ���ģ�ͽṹ��
	void CreateTexture(UINT textureArray[], LPSTR strFileName, int textureID);//  ���ļ��д�������
	int  GetString(char *);								// ��һ���ַ���
	void ReadChunk(tChunk *);							// ����һ����
	void ReadNextChunk(t3DModel *pModel, tChunk *);		// ����һ����
	void ReadNextObjChunk(t3DModel *pModel, t3DObject *pObject, tChunk *);// ����һ�������
	void ReadNextMatChunk(t3DModel *pModel, tChunk *);	// ����һ�����ʿ�
	void ReadColor(tMatInfo *pMaterial, tChunk *pChunk);// ��������ɫ��RGBֵ
	void ReadVertices(t3DObject *pObject, tChunk *);	// ������Ķ���
	void ReadVertexIndices(t3DObject *pObject, tChunk *);// �����������Ϣ
	void ReadUVCoordinates(t3DObject *pObject, tChunk *);// ���������������
	void ReadObjMat(t3DModel *pModel, t3DObject *pObject, tChunk *pPreChunk);// ���������Ĳ�������
	void ComputeNormals(t3DModel *pModel);				// ������󶥵�ķ�����
	void CleanUp();										// �ر��ļ����ͷ��ڴ�ռ�
	FILE	*m_FilePointer;								// �ļ�ָ��
	tChunk	*m_CurrentChunk;
	tChunk	*m_TempChunk;
};
#endif //!defined (___3DS_H___)


