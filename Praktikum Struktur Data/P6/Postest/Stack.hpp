#ifndef __stack
#define __stack
#define maxStack 6

namespace Stack
{
    template <typename T>
    class ArrayStatis
    {

    public:
        bool isPenuh()
        {
            return top == maxStack;
        }

        bool isKosong()
        {
            return top == 0;
        }

        T getTop()
        {
            return elemen[top - 1];
        }

        void push(const T &data)
        {
            if (!isPenuh())
            {
                elemen[top++] = data;
                // nElemen++;
                return;
            }
            std::cout << "Stack Overflow" << std::endl;
        }

        void pop(T &temp)
        {
            if (!isKosong())
            {
                temp = elemen[--top];
                // std::cout << top << std::endl;
                // nElemen--;
                return;
            }
            std::cout << "Stack underflow" << std::endl;
        }

        void print()
        {
            if (!isKosong())
            {
                for (int a = top - 1; a >= 0; a--)
                {
                    std::cout << elemen[a] << std::endl;
                }
                return;
            }
            std::cout << "Stack Kosong" << std::endl;
        }

    private:
        T elemen[maxStack];
        int top = 0;
        int nElemen = 0;
    };
};

#endif
