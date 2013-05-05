using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;

namespace org.oha7.dotnet
{
    public class Property : INotifyPropertyChanged
    {
        private object obj;

        public object Value {
            get { 
                return obj; 
            }
            set { 
                obj = value; 
                if(PropertyChanged!=null)
                {
                    PropertyChanged(this, new PropertyChangedEventArgs("Value"));
                }
            }
        }


        public event PropertyChangedEventHandler PropertyChanged;
    }
}
