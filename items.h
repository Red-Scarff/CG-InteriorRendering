#ifndef ITEMS_H
#define ITEMS_H

#include "Texture.h"


class Scene {
public:

    Scene();
    ~Scene();

    // ���Ƴ����еĶ���
    void drawTableTop();
    void firstLeg();
    void secondLeg();
    void thirdLeg();
    void fourthLeg();
    void dGlassCube();
    void bk1();
    void bk2();
    void bk3();
    void pgs();
    void FloorShadowObj();
    void drawFloor();
    void drawSky();
    void drawWall();
    void drawWallM();
    void glasscube();
    void drawTable();
    void book1();
    void book1top();
    void book2();
    void book2top();
    void book3();
    void book3top();
    void pages();

private:
    // ��������
    float Rs; // ����Ĵ�С
    float Tw; // ���Ӷ����Ŀ�ȣ������Ŀ�ʼ��
    float Tl; // ���Ӷ����ĳ��ȣ������Ŀ�ʼ��
    float Th; // ���Ӷ����ĸ߶ȣ������Ŀ�ʼ��
    float Tt; // ���Ӷ����ĺ��
    float Ls; // �����ȵĴ�С

    float Bw; // �鱾�Ŀ�ȣ������Ŀ�ʼ��
    float Bl; // �鱾�ĳ��ȣ������Ŀ�ʼ��
    float Bh; // �鱾�ĸ߶ȣ������Ŀ�ʼ��
    float Bt; // �鱾����ĺ��
    float Btt; // �鱾1��2�ĺ��
    float Btt3; // �鱾3�ĺ��
    float Bb; // �鱾װ���ĺ��
    float ang1; // �鱾1����ת�Ƕ�
    float B2h; // �鱾2�ĸ߶�
    float B3h; // �鱾3�ĸ߶�
    float ang2; // �鱾2����ת�Ƕ�
    float ang3; // �鱾3����ת�Ƕ�

    float a; // �������λ��
    float b;
    float c;
    float d; // ������Ĵ�С
    float _min;
    float _max;
    float wll;
};

#endif ITEMS_H