Public Class Form1
    ' Cube Formula
    Private Sub CalcCube_Click(sender As Object, e As EventArgs) Handles CalcCube.Click
        Dim side As Double
        If Double.TryParse(CubeLengthText.Text, side) Then
            Dim surfaceArea As Double = 6 * Math.Pow(side, 2)
            Dim perimeter As Double = 12 * side
            Dim volume As Double = Math.Pow(side, 3)

            LabelCube.Text = $"[Cube]" & vbCrLf &
                             $"Surface Area: {surfaceArea:F2}" & vbCrLf &
                             $"Perimeter: {perimeter:F2}" & vbCrLf &
                             $"Volume: {volume:F2}"
        Else
            MessageBox.Show("Enter a valid number for the cube side length.", "Input Error", MessageBoxButtons.OK, MessageBoxIcon.Error)
        End If
    End Sub

    ' Cuboid Formula
    Private Sub CalcCuboid_Click(sender As Object, e As EventArgs) Handles CalcCuboid.Click
        Dim length, width, height As Double
        If Double.TryParse(CuboidLengthText.Text, length) AndAlso
           Double.TryParse(CuboidWidthText.Text, width) AndAlso
           Double.TryParse(CuboidHeightText.Text, height) Then

            Dim surfaceArea As Double = 2 * (length * width + width * height + height * length)
            Dim perimeter As Double = 4 * (length + width + height)
            Dim volume As Double = length * width * height

            LabelCuboid.Text = $"[Cuboid]" & vbCrLf &
                               $"Surface Area: {surfaceArea:F2}" & vbCrLf &
                               $"Perimeter: {perimeter:F2}" & vbCrLf &
                               $"Volume: {volume:F2}"
        Else
            MessageBox.Show("Enter valid numbers for the cuboid dimensions.", "Input Error", MessageBoxButtons.OK, MessageBoxIcon.Error)
        End If
    End Sub

    'Cone Formula
    Private Sub CalcCone_Click(sender As Object, e As EventArgs) Handles CalcCone.Click
        Dim radius, Height As Double
        If Double.TryParse(ConeRadiusText.Text, radius) AndAlso
           Double.TryParse(ConeHeightText.Text, Height) Then
            ' Get the slant height via the Pythagorean theorem, familliar?
            Dim slantHeight As Double = Math.Sqrt(radius ^ 2 + Height ^ 2)
            Dim surfaceArea As Double = (Math.PI * radius * slantHeight) + (Math.PI * Math.Pow(radius, 2))
            Dim perimeter As Double = 2 * Math.PI * radius
            Dim volume As Double = (1 / 3) * Math.PI * Math.Pow(radius, 2) * Height

            LabelCone.Text = $"[Cone]" & vbCrLf &
                               $"Surface Area: {surfaceArea:F2}" & vbCrLf &
                               $"Perimeter: {perimeter:F2}" & vbCrLf &
                               $"Volume: {volume:F2}"
        Else
            MessageBox.Show("Enter valid numbers for the cone dimensions.", "Input Error", MessageBoxButtons.OK, MessageBoxIcon.Error)
        End If
    End Sub

    'Pyramid Formula
    Private Sub CalcPyramid_Click(sender As Object, e As EventArgs) Handles CalcPyramid.Click
        Dim baseLength, height As Double
        If Double.TryParse(PyramidHeightText.Text, height) AndAlso
            Double.TryParse(BaseLengthText.Text, baseLength) Then
            ' Calculate the slant height using the Pythagorean theorem
            Dim SlantHeight As Double = Math.Sqrt((baseLength / 2) ^ 2 + height ^ 2)
            Dim surfaceArea As Double = Math.Pow(baseLength, 2) + 2 * baseLength * SlantHeight
            Dim perimeter As Double = 4 * baseLength
            Dim volume As Double = (1 / 3) * Math.Pow(baseLength, 2) * height
            LabelPyramid.Text = $"[Pyramid]" & vbCrLf &
                               $"Surface Area: {surfaceArea:F2}" & vbCrLf &
                               $"Perimeter: {perimeter:F2}" & vbCrLf &
                               $"Volume: {volume:F2}"
        Else
            MessageBox.Show("Enter valid numbers for the pyramid dimensions.", "Input Error", MessageBoxButtons.OK, MessageBoxIcon.Error)
        End If
    End Sub

    ' Cylinder Formula
    Private Sub CalcCylinder_Click(sender As Object, e As EventArgs) Handles CalcCylinder.Click
        Dim radius, height As Double
        If Double.TryParse(CylinderRadiusText.Text, radius) AndAlso
           Double.TryParse(CylinderHeightText.Text, height) Then
            Dim surfaceArea As Double = 2 * Math.PI * radius * (radius + height)
            Dim perimeter As Double = 2 * Math.PI * radius
            Dim volume As Double = Math.PI * Math.Pow(radius, 2) * height
            LabelCylinder.Text = $"[Cylinder]" & vbCrLf &
                               $"Surface Area: {surfaceArea:F2}" & vbCrLf &
                               $"Perimeter: {perimeter:F2}" & vbCrLf &
                               $"Volume: {volume:F2}"
        Else
            MessageBox.Show("Enter valid numbers for the cylinder dimensions.", "Input Error", MessageBoxButtons.OK, MessageBoxIcon.Error)
        End If
    End Sub
End Class
