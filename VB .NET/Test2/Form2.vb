
Public Class Form2
    ' Use a DataSet to simulate the database
    Dim ds As New DataSet()
    Dim bs As New BindingSource()
    Dim position As Integer = 0

    Private Sub Form2_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        ' Create a DataTable
        Dim dt As New DataTable("Kayaks")
        dt.Columns.Add("ID")
        dt.Columns.Add("Name")
        dt.Columns.Add("Price", GetType(Double))

        ' Add sample data
        dt.Rows.Add("K001", "Single Kayak", 25.0)
        dt.Rows.Add("K002", "Double Kayak", 30.0)
        dt.Rows.Add("K003", "Family Kayak", 35.0)

        ' Add the DataTable to the DataSet
        ds.Tables.Add(dt)

        ' Bind the DataTable to a BindingSource
        bs.DataSource = ds.Tables("Kayaks")

        ' Bind BindingSource to controls
        DataGridView1.DataSource = bs
        txtID.DataBindings.Add("Text", bs, "ID")
        txtName.DataBindings.Add("Text", bs, "Name")
        txtPrice.DataBindings.Add("Text", bs, "Price")

        ' Format DataGridView
        With DataGridView1
            .ReadOnly = True
            .AllowUserToAddRows = False
            .AllowUserToDeleteRows = False
            .RowHeadersVisible = False
            .Columns("Price").DefaultCellStyle.Format = "N2"
        End With
    End Sub



    ' ============ CRUD OPERATIONS ============
    Private Sub btnAdd_Click(sender As Object, e As EventArgs) Handles btnAdd.Click
        Dim dt As DataTable = ds.Tables("Kayaks")
        dt.Rows.Add(txtID.Text, txtName.Text, Val(txtPrice.Text))
        MessageBox.Show("Record Added!")
    End Sub

    Private Sub btnDelete_Click(sender As Object, e As EventArgs) Handles btnDelete.Click
        If bs.Current IsNot Nothing Then
            bs.RemoveCurrent()
            MessageBox.Show("Record Deleted!")
        End If
    End Sub

    Private Sub btnNext_Click(sender As Object, e As EventArgs) Handles btnNext.Click
        If bs.Position < bs.Count - 1 Then
            bs.MoveNext()
        Else
            MessageBox.Show("End of record!")
        End If
    End Sub

    Private Sub btnPrevious_Click(sender As Object, e As EventArgs) Handles btnPrevious.Click
        If bs.Position > 0 Then
            bs.MovePrevious()
        Else
            MessageBox.Show("Beginning of record!")
        End If
    End Sub

    Private Sub btnSave_Click(sender As Object, e As EventArgs) Handles btnSave.Click
        ' Changes are automatically reflected in the DataSet through BindingSource
        MessageBox.Show("Record Updated (Saved)!")
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles btnLogin.Click
        Dim username As String = "admin"
        Dim password As String = "1234"

        If username = "admin" AndAlso password = "1234" Then
            MessageBox.Show("Login Successful")
        Else
            MessageBox.Show("Invalid username or password.")
        End If
    End Sub
End Class
