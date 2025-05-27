using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab2_Task_3
{
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            
            if (textBox1.Text != "")
            {
                for (int i = 0; i < Class1.count; i++)
                {
                    if (textBox1.Text == (string)Class1.userName[i])
                    {
                        MessageBox.Show("User Found Now Enter New Password");
                        Class1.index = i;
                        break;
                    }
                    else
                    {
                        MessageBox.Show("No User Found By This Name");
                    }
                }
            }
            else
            {
                MessageBox.Show("Username should not be empty");
            }
            
         }

        private void button2_Click(object sender, EventArgs e)
        {
            if (textBox1.Text != "")
            {
                Class1.Password[Class1.index] = textBox2.Text;
                MessageBox.Show("Password Changed Sucessfully");
                this.Hide();
                Form1 F1 = new Form1();
                F1.Show();
            }
            else
            {
                MessageBox.Show("Password should not be empty");
            }
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}
