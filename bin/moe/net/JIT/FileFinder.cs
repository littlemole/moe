using System;
using System.Collections.Generic;
using System.Text;

namespace mol
{
    class FileResolver
    {
        static public string FullPath(string f)
        {
            if (System.IO.Path.GetDirectoryName(f).Equals(String.Empty))
            {
                foreach (string dir in directories)
                {
                    string p = dir + "\\" + f;
                    if (System.IO.File.Exists(p))
                        return p;
                }
            }
            else
            {
                if (System.IO.File.Exists(f))
                {
                    return f;
                }
                foreach (string dir in directories)
                {
                    string p = dir + "\\" + f;
                    if (System.IO.File.Exists(p))
                        return p;
                }
            }
            return null;
        }

        static public void AddDirectory(string d)
        {
            if ( System.IO.Directory.Exists(d) )
                directories.Add(d);
        }

        static public void Clear()
        {
            directories.Clear();
        }

        private static List<string> directories = new List<string>();
    }
}
