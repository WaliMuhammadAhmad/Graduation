namespace Lab2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string[] User =new string[10] { "Wali", "Muhammad", "Justin Bieber", "Shawn Mendes", "Ed Shareen", "Chris Brown", "Charile Puth", "Jason Derulo","Luis Fonsi","The Weekend", };
            string[] Password = new string[10] { "Muhammad", "Wali", "Justin Bieber", "Shawn Mendes", "Ed Shareen", "Brown", "Charlie", "Jason", "Fonsi", "Weekend" };
            
            for(int i=0;i<10;i++)
            {
                if (textBox1.Text == User[i] && textBox2.Text==Password[i])
                {
                    label3.BackColor = System.Drawing.Color.Green;
                    label3.Text = "Validate User";
                    break;
                }
                else
                {
                    label3.BackColor = System.Drawing.Color.Red;
                    label3.Text = "Invalidate User";
                }
            }
        }
    }
}