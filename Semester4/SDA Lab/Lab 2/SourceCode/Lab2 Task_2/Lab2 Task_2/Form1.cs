namespace Lab2_Task_2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        string[] Username = new string[10];
        string[] Password = new string[10];
        int u = 0;
        
           
        private void button1_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < u; i++)
            {
                if (textBox1.Text == Username[i] && textBox2.Text == Password[i])
                {
                    label5.BackColor = System.Drawing.Color.Green;
                    label5.Text = "Validate User";
                    break;
                }
                else
                {
                    label5.BackColor = System.Drawing.Color.Red;
                    label5.Text = "Invalidate User";
                }
            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            Username[u] = textBox3.Text;
            Password[u] = textBox4.Text;
            u++;
            MessageBox.Show("Successfully Signed Up");
            textBox3.Text = "";
            textBox4.Text = "";
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}