using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GenerateTestingBatFile
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamWriter sw = new StreamWriter("spltoexe.bat");
            string pause = "pause\n";

            sw.Write("@echo off\ntitle .spl to .exe\n\n");
            for(int i = 1; i <= 160; i++)
            {
                if(i < 10)
                {
                    sw.Write("echo Test00{0}\n", i);
                    sw.Write("cgen < Test00{0}.spl > Test00{0}.c\n", i);
                    sw.Write("gcc -o Test00{0}.exe Test00{0}.c\n", i);
                    sw.Write("echo Test00{0}-successful\n\n", i);
                }
                else if (i < 100)
                {
                    sw.Write("echo Test0{0}\n", i);
                    sw.Write("cgen < Test0{0}.spl > Test0{0}.c\n", i);
                    sw.Write("gcc -o Test0{0}.exe Test0{0}.c\n", i);
                    sw.Write("echo Test0{0}-successful\n\n", i);
                }
                else
                {
                    sw.Write("echo Test{0}\n", i);
                    sw.Write("cgen < Test{0}.spl > Test{0}.c\n", i);
                    sw.Write("gcc -o Test{0}.exe Test{0}.c\n", i);
                    sw.Write("echo Test{0}-successful\n\n", i);
                }


            }

            sw.Write(pause);
            sw.Close();
        }
    }
}
