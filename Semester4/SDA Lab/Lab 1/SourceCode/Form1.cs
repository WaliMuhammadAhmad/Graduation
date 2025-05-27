namespace WinFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            textBox1.Text = "Hello World";
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //MessageBox.Show("Hello World");

            textBox1.Text = "Pakistan";
            textBox1.BackColor = System.Drawing.Color.Yellow;

            string name = "Pakistan1";

            if(textBox1.Text == name)
            {
                MessageBox.Show("Welcome to Pakistan");
            }
            else
                MessageBox.Show("Goodbye");

        }
    }
}