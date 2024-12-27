#include "imageloader.h" 
#include <assert.h>       
#include <fstream>       

using namespace std;

// ��������ĺ���
GLuint loadTexture(Image* image) {
    GLuint* textures = new GLuint[11];  // ����һ������11������ID������
    glGenTextures(12, textures);        // ����12������ID��Ϊ��������Ԥ���ռ䣩
    glBindTexture(GL_TEXTURE_2D, *textures);  // �󶨵�һ������2D����Ŀ��
    glTexImage2D(GL_TEXTURE_2D,  // Ŀ���������ͣ�2D����
        0,              // ������0��ʾ��������
        GL_RGB,         // �����ʽ��RGB��
        image->width, image->height,  // ����Ŀ�Ⱥ͸߶�
        0,              // �߿��ȣ�ͨ��Ϊ0��
        GL_RGB,         // �������ݸ�ʽ��RGB��
        GL_UNSIGNED_BYTE,  // �����������ͣ��޷����ֽڣ�
        image->pixels   // ʵ�ʵ���������
    );
    return *textures;  // ���ص�һ������ID
}

// ����������ID����
GLuint _textureId1;
GLuint _textureId2;
GLuint _textureId3;
GLuint _textureId4;
GLuint _textureId5;
GLuint _textureId6;
GLuint _textureId7;
GLuint _textureId8;
GLuint _textureId9;
GLuint _textureId10;
GLuint _textureId11;
GLuint _textureId12;

// ��ʼ����Ⱦ�ĺ���
void initRender() {
    glEnable(GL_DEPTH_TEST);  // ������Ȳ���
    glEnable(GL_COLOR_MATERIAL);  // ������ɫ����
    glEnable(GL_BLEND);  // ���û�ϣ�����͸��Ч����
    glEnable(GL_NORMALIZE);  // ���÷��߹�һ��
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  // ���û�Ϻ���

    // ���ز��󶨶������
    Image* image1 = loadBMP("assets/cake.bmp");
    _textureId1 = loadTexture(image1);
    delete image1;
    Image* image2 = loadBMP("assets/pages_2.bmp");
    _textureId2 = loadTexture(image2);
    delete image2;
    Image* image3 = loadBMP("assets/wood.bmp");
    _textureId3 = loadTexture(image3);
    delete image3;
    Image* image4 = loadBMP("assets/cover.bmp");
    _textureId4 = loadTexture(image4);
    delete image4;
    Image* image5 = loadBMP("assets/cvr.bmp");
    _textureId5 = loadTexture(image5);
    delete image5;
    Image* image6 = loadBMP("assets/2cover.bmp");
    _textureId6 = loadTexture(image6);
    delete image6;
    Image* image7 = loadBMP("assets/2cvr.bmp");
    _textureId7 = loadTexture(image7);
    delete image7;
    Image* image8 = loadBMP("assets/3cover.bmp");
    _textureId8 = loadTexture(image8);
    delete image8;
    Image* image9 = loadBMP("assets/3cvr.bmp");
    _textureId9 = loadTexture(image9);
    delete image9;
    Image* image10 = loadBMP("assets/wall.bmp");
    _textureId10 = loadTexture(image10);
    delete image10;
    Image* image11 = loadBMP("assets/sky.bmp");
    _textureId11 = loadTexture(image11);
    delete image11;
    Image* image12 = loadBMP("assets/floor.bmp");
    _textureId12 = loadTexture(image12);
    delete image12;


    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // ���ñ�����ɫΪ��ɫ��͸����Ϊ1
}

// Image��Ĺ��캯��
Image::Image(char* ps, int w, int h) : pixels(ps), width(w), height(h) {}

// Image�����������
Image::~Image() {
    delete[] pixels;  // �ͷ��������ݵ��ڴ�
}

namespace {
    // ��4�ֽ��ַ�����ת��Ϊ����
    int toInt(const char* bytes) {
        return (int)(
            ((unsigned char)bytes[3] << 24) |
            ((unsigned char)bytes[2] << 16) |
            ((unsigned char)bytes[1] << 8) |
            (unsigned char)bytes[0]
            );
    }

    // ��2�ֽ��ַ�����ת��Ϊ��������С����
    short toShort(const char* bytes) {
        return (short)(((unsigned char)bytes[1] << 8) |
            (unsigned char)bytes[0]);
    }

    // ���ļ����ж�ȡ4�ֽڲ�ת��Ϊ����
    int readInt(ifstream& input) {
        char buffer[4];
        input.read(buffer, 4);
        return toInt(buffer);
    }

    // ���ļ����ж�ȡ2�ֽڲ�ת��Ϊ������
    short readShort(ifstream& input) {
        char buffer[2];
        input.read(buffer, 2);
        return toShort(buffer);
    }

    // ������auto_ptr������ָ�룬����������
    template<class T>
    class auto_array {
    private:
        T* array;  // ָ�������ָ��
        mutable bool isReleased;  // ��������Ƿ����ͷ�
    public:
        explicit auto_array(T* array_ = NULL) :
            array(array_), isReleased(false) {
        }

        auto_array(const auto_array<T>& aarray) {
            array = aarray.array;
            isReleased = aarray.isReleased;
            aarray.isReleased = true;
        }

        ~auto_array() {
            if (!isReleased && array != NULL) {
                delete[] array;  // �ͷ������ڴ�
            }
        }

        T* get() const {
            return array;
        }

        T& operator*() const {
            return *array;
        }

        void operator=(const auto_array<T>& aarray) {
            if (!isReleased && array != NULL) {
                delete[] array;
            }
            array = aarray.array;
            isReleased = aarray.isReleased;
            aarray.isReleased = true;
        }

        T* operator->() const {
            return array;
        }

        T* release() {
            isReleased = true;
            return array;
        }

        void reset(T* array_ = NULL) {
            if (!isReleased && array != NULL) {
                delete[] array;
            }
            array = array_;
        }

        T* operator+(int i) {
            return array + i;
        }

        T& operator[](int i) {
            return array[i];
        }
    };
}

// ����BMPͼ��ĺ���
Image* loadBMP(const char* filename) {
    ifstream input;
    input.open(filename, ifstream::binary);  // �Զ�����ģʽ���ļ�
    assert(!input.fail() || !"Could not find file");  // �����ļ�����
    char buffer[2];
    input.read(buffer, 2);
    assert(buffer[0] == 'B' && buffer[1] == 'M' || !"Not a bitmap file");  // �����ļ���BMP��ʽ
    input.ignore(8);
    int dataOffset = readInt(input);  // ��ȡ�������ݵ�ƫ����

    // ��ȡBMP�ļ�ͷ
    int headerSize = readInt(input);  // ��ȡͷ��С
    int width;
    int height;
    switch (headerSize) {
    case 40:
        // V3��ʽ
        width = readInt(input);
        height = readInt(input);
        input.ignore(2);
        assert(readShort(input) == 24 || !"Image is not 24 bits per pixel");  // ����ͼ��Ϊ24λ
        assert(readShort(input) == 0 || !"Image is compressed");  // ����ͼ��δѹ��
        break;
    case 12:
        // OS/2 V1��ʽ
        width = readShort(input);
        height = readShort(input);
        input.ignore(2);
        assert(readShort(input) == 24 || !"Image is not 24 bits per pixel");
        break;
    case 64:
        // OS/2 V2��ʽ
        assert(!"Can't load OS/2 V2 bitmaps");
        break;
    case 108:
        // Windows V4��ʽ
        assert(!"Can't load Windows V4 bitmaps");
        break;
    case 124:
        // Windows V5��ʽ
        assert(!"Can't load Windows V5 bitmaps");
        break;
    default:
        assert(!"Unknown bitmap format");
    }

    // ��ȡ��������
    int bytesPerRow = ((width * 3 + 3) / 4) * 4 - (width * 3 % 4);  // ����ÿ�е��ֽ���
    int size = bytesPerRow * height;  // �������ֽ���
    auto_array<char> pixels(new char[size]);  // �����������ݵ��ڴ�
    input.seekg(dataOffset, ios_base::beg);  // ��ת���������ݵ�λ��
    input.read(pixels.get(), size);  // ��ȡ��������

    // ����������ת��Ϊ��ȷ�ĸ�ʽ
    auto_array<char> pixels2(new char[width * height * 3]);  // �����µ����������ڴ�
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < 3; c++) {
                pixels2[3 * (width * y + x) + c] =
                    pixels[bytesPerRow * y + 3 * x + (2 - c)];  // ����������������
            }
        }
    }

    input.close();  
    return new Image(pixels2.release(), width, height);  // ����Image����
}